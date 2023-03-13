#include <string>

class Response {
 private:
  static std::string m_serv_name;

 public:
  static std::string rplWelcome(std::string nickname, std::string username,
                                std::string hostname);
  static std::string rplYourHost(void);
  static std::string rplWhoisUser(std::string requestNickname,
                                  std::string nickname, std::string username,
                                  std::string hostname, std::string realname);
  static std::string rplWhoisServer(std::string requestNickname,
                                    std::string nickname);
  static std::string rplWhoisChannels(std::string requestNickname,
                                      std::string nickname, std::string chlist);
  static std::string rplEndofWhois(std::string requestNickname,
                                   std::string nickname);
  static std::string rplUModeIs(std::string ninckname, std::string mode);
  static std::string rplYoureOper(void);
  static std::string rplKillDone(std::string nickname, std::string msg);

  static std::string errNotRegistered(std::string cmd);
  static std::string errNeedMoreParams(std::string cmd);
  static std::string errNicknameInUse(std::string nickname);
  static std::string errNoNicknameGiven(void);
  static std::string errNoSuchNick(std::string cmd, std::string nickname);
  static std::string errUsersDontMatch(void);
  static std::string errUmodeUnknownFlag(void);
  static std::string errUnknownMode(std::string mode, std::string channel_name);
  static std::string errChaNoPrivsNeeded(std::string channel_name);
  static std::string errUserNotInChannel(std::string nick,
                                         std::string channel_name);
  static std::string errNoPrivileges(void);
  static std::string errPassWDMismatch(void);

  static std::string noticeNick(std::string prevNickname, std::string nickname,
                                std::string username, std::string hostname);
  static std::string responsePong(void);
  static std::string setMode(std::string nickname, std::string username,
                             std::string hostname, std::string mode);
  static std::string noticeKill(std::string nickname, std::string username,
                                std::string hostname, std::string kill_msg);

  static void set_m_serv_name(std::string serv_name);

  // 필요할때마다 추가
};
