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
  static std::string rplWhoisServer(std::string requestNickname, std::string nickname);
  static std::string rplWhoisChannels(std::string requestNickname, std::string nickname, std::string chlist);
  static std::string rplEndofWhois(std::string requestNickname, std::string nickname);


  static std::string errNotRegistered(std::string cmd);
  static std::string errNeedMoreParams(std::string cmd);
  static std::string errNicknameInUse(std::string nickname);
  static std::string errNoNicknameGiven(void);
  static std::string errNoSuchNick(std::string cmd, std::string nickname);

  static std::string noticeNick(std::string prevNickname, std::string nickname,
                                std::string username, std::string hostname);

  static std::string responsePong(void);

  static void set_m_serv_name(std::string serv_name);

  // 필요할때마다 추가
};
