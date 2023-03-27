#include "Command_bonus.hpp"
#include "Server_bonus.hpp"

/*==============================
-----------generator------------
===============================*/

Mode::Mode(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Mode::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "MODE") {
    // 1st Argument
    std::vector<std::string> params = Util::split(request, ' ');

    if (params.size() < 1) {  // 본인 채널 옵션 보내기
      c.sendMsg(Response::errNeedMoreParams("MODE"));
      return (true);
    }

    std::string type = params[0];
    if (type[0] == '!' || type[0] == '&' || type[0] == '#' ||
        type[0] == '+')  // Channel Mode Message
    {
      if (params.size() > 3) return (true);
      // 채널 존재 체킹
      try {
        m_server->get_m_channel(params[0]);
      } catch (const std::exception &e) {
        c.sendMsg(Response::errNoSuchChannel(cmd, params[0]));
        return (true);
      }
      if (params.size() == 1) {  // 본인 채널 옵션 보내기
        Channel &channel = m_server->get_m_channel(params[0]);
        try {
          channel.get_m_client(c.get_m_nickname());
        } catch (const std::exception &e) {
          c.sendMsg(Response::errNotOnChannel(params[0]));
          return (true);
        }
        std::string mode = "";
        std::string modeParams = "";

        if (channel.get_m_limit() != -1) {
          mode += "+l ";
          modeParams += Util::itoa(channel.get_m_limit(), 10);
          modeParams += " ";
        }
        if (!channel.get_m_password().empty()) {
          mode += "+k ";
          modeParams += channel.get_m_password();
        }
        if (channel.get_m_notice_flag()) {
          mode += "+n ";
        }
        c.sendMsg(Response::rplChannelModeIs(params[0], mode, modeParams));
        return (true);
      }
      // 2nd Argument
      std::string channel_name = type;
      // 3rd Argument
      std::string option = params[1];

      Channel &channel = m_server->get_m_channel(channel_name);
      try {
        if (channel.get_m_channelauth(c.get_m_nickname()).get_m_oper()) {
          if (!option.compare("+n")) {
            if (params.size() > 2) return (true);
            channel.set_m_notice_flag(true);
            channel.sendMsg(
                Response::setChMode(c.get_m_nickname(), c.get_m_username(),
                                    c.get_m_hostname(), channel_name, option));
            return (true);
          } else if (!option.compare("-n")) {
            if (params.size() > 2) return (true);
            channel.set_m_notice_flag(false);
            channel.sendMsg(
                Response::setChMode(c.get_m_nickname(), c.get_m_username(),
                                    c.get_m_hostname(), channel_name, option));
            return (true);
          } else if (!option.compare("-l")) {
            if (params.size() > 2) return (true);
            channel.set_m_limit(-1);
            channel.sendMsg(
                Response::setChMode(c.get_m_nickname(), c.get_m_username(),
                                    c.get_m_hostname(), channel_name, option));
            return (true);
          }

          if (params.size() < 3) {
            if (!option.compare("+k") || !option.compare("-k") ||
                !option.compare("+o") || !option.compare("-o") ||
                !option.compare("+v") || !option.compare("-v") ||
                !option.compare("+l"))
              c.sendMsg(Response::errNeedMoreParams("MODE"));
            else
              c.sendMsg(Response::errUnknownMode(option, channel_name));
            return (true);
          }

          // Read Param
          std::string param = params[2];
          if (!option.compare("+k")) {
            channel.set_m_password(param);
            channel.sendMsg(Response::setChMode(
                c.get_m_nickname(), c.get_m_username(), c.get_m_hostname(),
                channel_name, option + " " + param));
            return (true);
          } else if (!option.compare("-k")) {
            if (param == channel.get_m_password()) {
              channel.set_m_password("");
              channel.sendMsg(Response::setChMode(
                  c.get_m_nickname(), c.get_m_username(), c.get_m_hostname(),
                  channel_name, option + " " + param));
              return (true);
            } else {
              c.sendMsg(Response::errBadChannelKey(channel_name));
              return (true);
            }
          }

          // Check User(Param) in Channel
          try {
            // Mode O
            if (!option.compare("+o")) {
              channel.get_m_channelauth(param).set_m_oper(true);
              channel.sendMsg(Response::setChMode(
                  c.get_m_nickname(), c.get_m_username(), c.get_m_hostname(),
                  channel_name, option + " " + param));
            } else if (!option.compare("-o")) {
              channel.get_m_channelauth(param).set_m_oper(false);
              channel.sendMsg(Response::setChMode(
                  c.get_m_nickname(), c.get_m_username(), c.get_m_hostname(),
                  channel_name, option + " " + param));
            }

            // Mode V
            else if (!option.compare("+v")) {
              channel.get_m_channelauth(param).set_m_voice(true);
              channel.sendMsg(Response::setChMode(
                  c.get_m_nickname(), c.get_m_username(), c.get_m_hostname(),
                  channel_name,
                  option + " " + param));
            } else if (!option.compare("-v")) {
              channel.get_m_channelauth(param).set_m_voice(false);
              channel.sendMsg(Response::setChMode(
                  c.get_m_nickname(), c.get_m_username(), c.get_m_hostname(),
                  channel_name, option + " " + param));
            }

            // Mode L
            else if (!option.compare("+l")) {
              channel.set_m_limit(atoi(param.c_str()));
              channel.sendMsg(Response::setChMode(
                  c.get_m_nickname(), c.get_m_username(), c.get_m_hostname(),
                  channel_name,
                  option + " " + param));
            }
            // No Mode
            else
              c.sendMsg(Response::errUnknownMode(option, channel_name));
          } catch (const std::exception &e)  // Not In Channel Client(param)
          {
            c.sendMsg(Response::errUserNotInChannel(param, channel_name));
            return (true);
          }
        } else  // No Permission to use Mode
        {
          c.sendMsg(
              Response::errChaNoPrivsNeeded(channel_name));  // No Permission
        }
      } catch (const std::exception &e)  // Not In Channel Client(c)
      {
        c.sendMsg(
            Response::errUserNotInChannel(c.get_m_nickname(), channel_name));
      }
    } else  // User Mode Message
    {
      if (params.size() > 2)
        return (true);
      // 옵션에 대한 인자가 들어오지 않았을 경우 현재 적용중인 옵션을 표시
      else if (params.size() == 1) {
        if (type != c.get_m_nickname()) {
          try {
            m_server->get_m_client(type);
            c.sendMsg(Response::errUsersDontMatch());
          } catch (const std::exception &e) {
            c.sendMsg(Response::errNoSuchNick(cmd, type));
          }
        } else {
          std::string mode = "";
          if (c.get_m_oper_flag()) mode += "+o ";
          if (c.get_m_invisible_flag()) mode += "+i";
          c.sendMsg(Response::rplUModeIs(c.get_m_nickname(), mode));
        }
      } else {
        std::string option = params[1];

        // 유저 모드는 자기 자신에 대한 명령이 왔을 때만 적용 가능
        if (type == c.get_m_nickname()) {
          // 자기 자신에 대한 +o는 무시되어야함
          if (!option.compare("+o")) c.sendMsg(Response::errNoPrivileges());
          // 자기 자신에 대한 -o는 적용
          else if (!option.compare("-o")) {
            if (c.get_m_oper_flag())
              c.sendMsg(Response::setMode(c.get_m_nickname(),
                                          c.get_m_username(),
                                          c.get_m_hostname(), option));
          } else if (!option.compare("+i")) {
            if (!c.get_m_invisible_flag()) {
              c.sendMsg(Response::setMode(c.get_m_nickname(),
                                          c.get_m_username(),
                                          c.get_m_hostname(), option));
              c.set_m_invisible_flag(true);
            }
          } else if (!option.compare("-i")) {
            if (c.get_m_invisible_flag()) {
              c.sendMsg(Response::setMode(c.get_m_nickname(),
                                          c.get_m_username(),
                                          c.get_m_hostname(), option));
              c.set_m_invisible_flag(false);
            }
          }
          // o,i를 제외한 다른 플래그들은 에러처리
          else
            c.sendMsg(Response::errUmodeUnknownFlag());
        } else {
          try {
            m_server->get_m_client(type);
            c.sendMsg(Response::errUsersDontMatch());
          } catch (const std::exception &e) {
            c.sendMsg(Response::errNoSuchNick(cmd, type));
          }
        }
      }
    }
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}
