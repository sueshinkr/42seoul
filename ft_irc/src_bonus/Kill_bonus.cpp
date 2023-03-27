#include "Command_bonus.hpp"
#include "Server_bonus.hpp"

/*==============================
-----------generator------------
===============================*/

Kill::Kill(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Kill::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "kill") {
    std::vector<std::string> params = Util::split(request, ' ');

    // 정해진 형식에 맞게 들어오지 않은 경우
    if (params.size() > 2)
      return (true);
    else if (params.size() < 1) {
      c.sendMsg(Response::errNeedMoreParams(cmd));
      return (true);
    }

    // 권한이 없는 경우
    if (!c.get_m_oper_flag()) {
      c.sendMsg(Response::errNoPrivileges());
    } else {
      std::string target_nickname = params[0];
      std::string kill_msg;
      if (params.size() == 2)
        kill_msg = params[1];
      else
        kill_msg = "Default";
      try {
        Client &target = m_server->get_m_client(target_nickname);
        // 킬한 유저에게 메시지 전송
        c.sendMsg(Response::rplKillDone(c.get_m_nickname(), target_nickname));
        // 킬 당한 타겟에게 메시지 전송
        target.sendMsg(Response::noticeKill(c.get_m_nickname(),
                                            c.get_m_username(),
                                            c.get_m_hostname(), kill_msg));
        // 타겟이 속한 채널에 메시지 전송
        std::vector<std::string> chlist = target.get_m_channel();
        for (std::vector<std::string>::iterator iter = chlist.begin();
             iter != chlist.end(); iter++) {
          Channel &ch = m_server->get_m_channel(*iter);
          ch.sendMsg(Response::partChannel(
              target.get_m_nickname(), target.get_m_username(),
              target.get_m_hostname(), ch.get_m_channel_name(),
              "Killed by Operator"));
        }
        m_server->disconnectClient(target.get_m_clnt_fd());
      } catch (const std::exception &e) {
        c.sendMsg(Response::errNoSuchNick(cmd, target_nickname));
      }
    }
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}
