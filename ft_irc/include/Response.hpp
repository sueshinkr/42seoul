#include <string>

class Response {
 private:
  static std::string m_serv_name;

 public:
  static std::string rplWelcome(std::string nickname, std::string username,
                                std::string hostname);
  static std::string rplYourHost(void);
  static std::string rplSaveNick(std::string prevNickname, std::string nickname, std::string user_name,
                                std::string hostname);
  static std::string rplWhoisUser(std::string nickname, std::string username, std::string hostname, std::string realname);

  static std::string errNotRegistered(std::string cmd);
  static std::string errNeedMoreParams(std::string cmd);
  static std::string errNicknameInUse(std::string nick_name);
  static std::string errNoNicknameGiven(void);

  static void set_m_serv_name(std::string serv_name);

  // 필요할때마다 추가
};
