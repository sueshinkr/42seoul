#include "Command.hpp"
#include "Server.hpp"

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
    size_t prev = 0;
    size_t cur = request.find(" ");

    // 1st Argument
    if (cur == std::string::npos) {
      c.sendMsg(Response::errNeedMoreParams("Mode"));
      return (true);
    }
    std::string type = request.substr(prev, cur - prev);
    prev = cur + 1;
    cur = request.find(" ", prev);

    if (type[0] == '!' || type[0] == '&' || type[0] == '#' ||
        type[0] == '+')  // Channel Mode Message
    {
      // Param이 부족할 때
      if (cur == std::string::npos) {
        c.sendMsg(Response::errNeedMoreParams("Mode"));
        return (true);
      }

      // 2nd Argument
      std::string channel_name = request.substr(prev, cur - prev);
      prev = cur + 1;
      cur = request.find(" ", prev);

      // Param이 부족할 때
      if (cur == std::string::npos) {
        c.sendMsg(Response::errNeedMoreParams("Mode"));
        return (true);
      }

      // 3rd Argument
      std::string option = request.substr(prev, cur - prev);
      prev = cur + 1;
      cur = request.find(" ", prev);

      // 채널이 없을 때 에러 처리 필요
      Channel &channel = m_server->get_m_channel(channel_name);
      try {
        if (channel.get_m_channelauth(c.get_m_nickname()).get_m_oper()) {
          if (!option.compare("+n")) {
            channel.set_m_notice_flag(true);
            channel.sendMsg(request);  // 모든 채널에 보내지지 않음
            return (true);
          } else if (!option.compare("-n")) {
            channel.set_m_notice_flag(false);
            channel.sendMsg(request);  // 모든 채널에 보내지지 않음
            return (true);
          }
          if (cur == std::string::npos) {
            c.sendMsg(Response::errNeedMoreParams("Mode"));
            return (true);
          }

          // Read Param
          std::string param = request.substr(prev, cur - prev);
          if (!option.compare("+k")) {
            channel.set_m_password(param);
            channel.sendMsg(request);  // 모든 채널에 보내지지 않음
          } else if (!option.compare("-k")) {
            if (param == channel.get_m_password()) {
              channel.set_m_password(NULL);
              channel.sendMsg(request);  // 모든 채널에 보내지지 않음
            } else
              ;  // Wrong Password
          }

          // Check User(Param) in Channel
          try {
            // Mode O
            if (!option.compare("+o")) {
              channel.get_m_channelauth(param).set_m_oper(true);
              channel.sendMsg(request);  // 모든 채널에 보내지지 않음
            } else if (!option.compare("-o")) {
              channel.get_m_channelauth(param).set_m_oper(false);
              channel.sendMsg(request);  // 모든 채널에 보내지지 않음
            }

            // Mode V
            else if (!option.compare("+v")) {
              channel.get_m_channelauth(param).set_m_voice(true);
              channel.sendMsg(request);  // 모든 채널에 보내지지 않음
            } else if (!option.compare("-v")) {
              channel.get_m_channelauth(param).set_m_voice(false);
              channel.sendMsg(request);  // 모든 채널에 보내지지 않음
            }

            // Mode L
            else if (!option.compare("+l")) {
              channel.set_m_limit(atoi(param.c_str()));
              channel.sendMsg(request);  // 모든 채널에 보내지지 않음
            } else if (!option.compare("-l")) {
              channel.set_m_limit(-1);
              channel.sendMsg(request);  // 모든 채널에 보내지지 않음
            }

            // No Mode
            else
              channel.sendMsg(Response::errUnknownMode(option, channel_name));
          } catch (const std::exception &e)  // Not In Channel Client(param)
          {
            c.sendMsg(Response::errUserNotInChannel(param, channel_name));
          }
        } else  // No Permission to use Mode
        {
          channel.sendMsg(
              Response::errChaNoPrivsNeeded(channel_name));  // No Permission
        }
      } catch (const std::exception &e)  // Not In Channel Client(c)
      {
        c.sendMsg(
            Response::errUserNotInChannel(c.get_m_nickname(), channel_name));
      }
    } else  // User Mode Message
    {
      try {
        std::cout << type << std::endl;
        Client &user = m_server->get_m_client(type);

        std::string option = request.substr(prev, cur - prev);
        prev = cur + 1;
        cur = request.find(" ", prev);

        // 권한이 없을 때 에러 문구 처리 필요
        if (c.get_m_oper_flag() && !option.compare("+o")) {
          user.set_m_oper_flag(true);
          c.sendMsg(request);
        } else if (c.get_m_oper_flag() && !option.compare("-o")) {
          user.set_m_oper_flag(false);
          c.sendMsg(request);
        } else if (!option.compare("+i")) {
          ;  // Need Review
        } else
          c.sendMsg(Response::errUmodeUnknownFlag());
      } catch (const std::exception &error) {
        c.sendMsg(Response::errUsersDontMatch());
      }
    }
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}