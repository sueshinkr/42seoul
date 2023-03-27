#include "Command.hpp"
#include "Server.hpp"

/*==============================
-----------generator------------
===============================*/

Whois::Whois(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Whois::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "WHOIS") {
    std::vector<std::string> params = Util::split(request, ' ');

    // 정해진 형식에 맞게 들어오지 않은 경우
    if (params.size() > 1)
      return (true);
    else if (params.size() < 1) {
      c.sendMsg(Response::errNeedMoreParams(cmd));
      return (true);
    }

    std::string response = "";
    try {
      Client &target = m_server->get_m_client(request);
      response += Response::rplWhoisUser(
          c.get_m_nickname(), target.get_m_nickname(), target.get_m_username(),
          target.get_m_hostname(), target.get_m_realname());
      response +=
          Response::rplWhoisServer(c.get_m_nickname(), target.get_m_nickname());

      std::vector<std::string> ch = target.get_m_channel();
      if (!ch.empty()) {
        std::string chlist = "";
        for (std::vector<std::string>::iterator iter = ch.begin();
             iter != ch.end(); iter++) {
          chlist += (*iter) + " ";
        }
        response += Response::rplWhoisChannels(c.get_m_nickname(),
                                               target.get_m_nickname(), chlist);
      }
      response +=
          Response::rplEndofWhois(c.get_m_nickname(), target.get_m_nickname());
      c.sendMsg(response);
    } catch (const std::exception &error) {
      c.sendMsg(Response::errNoSuchNick(cmd, request));
    }
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}
