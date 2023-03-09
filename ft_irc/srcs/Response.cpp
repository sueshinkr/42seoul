#include "Response.hpp"

std::string Response::rplWelcome(std::string nick_name, std::string user_name,
                                 std::string host_name) {
  return (":" + m_serv_name + " 001 " + nick_name +
          " :Welcome to the Internet Relay Network " + nick_name + "!" +
          user_name + "@" + host_name + "\r\n");
}

std::string Response::rplYourHost(void) {
  return (":" + m_serv_name + " 002 * :Your host is " + m_serv_name + "\r\n");
}

std::string Response::errNotRegistered(std::string cmd) {
  return (":" + m_serv_name + " 451 " + cmd + " :You have not registered\r\n");
}

std::string Response::errNeedMoreParams(std::string cmd) {
  return (":" + m_serv_name + " 461 " + cmd + " :Not enough parameters\r\n");
}

std::string Response::errNicknameInUse(std::string nick_name) {
  return (":" + m_serv_name + " 433 Nick " + nick_name +
          " :Nickname is already in use\r\n");
}

std::string Response::errNoNicknameGiven(void) {
  return (":" + m_serv_name + " 431 Nick :No nickname given\r\n");
}

void Response::set_m_serv_name(std::string serv_name) {
  m_serv_name = serv_name;
}
