#include "Command_bonus.hpp"
#include "Server_bonus.hpp"

/*==============================
-----------generator------------
===============================*/

Part::Part(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Part::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "PART") {
    std::vector<std::string> params = Util::split(request, ' ');
    if (params.size() < 1) {
      c.sendMsg(Response::errNeedMoreParams(cmd));
      return (true);
    }
    if (params.size() > 2) return (true);
    std::vector<std::string> channels = Util::split(params[0], ',');
    for (size_t i = 0; i < channels.size(); i++) {
      try {
        if (channels[i][0] != '#' && channels[i][0] != '&' &&
            channels[i][0] != '!' && channels[i][0] != '+')
          continue;
        Channel &channel = m_server->get_m_channel(channels[i]);
        try {
          channel.get_m_client(c.get_m_nickname());
        } catch (const std::exception &e) {
          c.sendMsg(Response::errNotOnChannel(channels[i]));
          return (true);
        }
        if (params.size() == 2) {
          channel.sendMsg(Response::partChannel(
              c.get_m_nickname(), c.get_m_username(), c.get_m_hostname(),
              channels[i], params[1]));
          c.del_m_channel(channels[i]);
          channel.del_m_client(c.get_m_nickname());
          if (channel.get_numOfpeople() == 0) {
            m_server->del_m_ch_to_channel(channel.get_m_channel_name());
          }
        } else {
          channel.sendMsg(
              Response::partChannel(c.get_m_nickname(), c.get_m_username(),
                                    c.get_m_hostname(), channels[i]));
          c.del_m_channel(channels[i]);
          channel.del_m_client(c.get_m_nickname());
          if (channel.get_numOfpeople() == 0) {
            m_server->del_m_ch_to_channel(channel.get_m_channel_name());
          }
        }
      } catch (const std::exception &e) {
        c.sendMsg(Response::errNoSuchChannel(cmd, channels[i]));
      }
    }
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}