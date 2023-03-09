#include <string>

class Response {
 private:
  static std::string m_serv_name;

 public:
  static std::string rplWelcome(std::string nick_name, std::string user_name,
                                std::string host_name);
  static std::string rplYourHost(void);
  static std::string errNotRegistered(std::string cmd);
  static std::string errNeedMoreParams(std::string cmd);
  static std::string errNicknameInUse(std::string nick_name);
  static std::string errNoNicknameGiven(void);

  static void set_m_serv_name(std::string serv_name);

  // 필요할때마다 추가
};