#include "Response.hpp"

/*==============================
--------------RPL_--------------
===============================*/

std::string Response::rplWelcome(std::string nickname, std::string username,
                                 std::string hostname) {
  return (":" + m_serv_name + " 001 " + nickname +
          " :Welcome to the Internet Relay Network " + nickname + "!" +
          username + "@" + hostname + "\r\n");
}

std::string Response::rplYourHost(void) {
  return (":" + m_serv_name + " 002 * :Your host is " + m_serv_name + "\r\n");
}

std::string Response::rplWhoisUser(std::string requestNickname,
                                   std::string nickname, std::string username,
                                   std::string hostname, std::string realname) {
  return (":" + m_serv_name + " 311 " + requestNickname + " " + nickname + " " +
          username + " " + hostname + " * :" + realname + "\r\n");
}

std::string Response::rplWhoisServer(std::string requestNickname, std::string nickname)
{
	return (":" + m_serv_name + " 312 " + requestNickname + " " + nickname + " testServer :version 1.0\r\n");
}

// 채널관련 동작 완성후 확인해봐야됨
std::string Response::rplWhoisChannels(std::string requestNickname, std::string nickname, std::string chlist)
{
	return (":" + m_serv_name + " 319 " + nickname + " : " + chlist + "\r\n");//:is an IRC Operator\r\n");
}

std::string Response::rplEndofWhois(std::string requestNickname, std::string nickname)
{
	return (":" + m_serv_name + " 318 " + requestNickname + " " + nickname + "\r\n");
}

/*==============================
--------------ERR_--------------
===============================*/

std::string Response::errNotRegistered(std::string cmd) {
  return (":" + m_serv_name + " 451 " + cmd + " :You have not registered\r\n");
}

std::string Response::errNeedMoreParams(std::string cmd) {
  return (":" + m_serv_name + " 461 " + cmd + " :Not enough parameters\r\n");
}

std::string Response::errNicknameInUse(std::string nick_name) {
  return (":" + m_serv_name + " 433 * " + nick_name +
          " :Nickname is already in use\r\n");
}

std::string Response::errNoNicknameGiven(void) {
  return (":" + m_serv_name + " 431 Nick :No nickname given\r\n");
}

std::string Response::errNoSuchNick(std::string cmd, std::string nickname) {
  return (":" + m_serv_name + " 401 " + cmd + " :" + nickname + "\r\n");
}

/*==============================
---------NON_NUMERIC RPL--------
===============================*/

std::string Response::noticeNick(std::string prevNickname, std::string nickname,
                                 std::string username, std::string hostname) {
  return (":" + prevNickname + "!" + username + "@:" + hostname + " NICK " +
          nickname + "\r\n");
}

std::string Response::responsePong(void) {
  return ("PONG " + m_serv_name + "\r\n");
}

/*==============================
----------set_function----------
===============================*/

void Response::set_m_serv_name(std::string serv_name) {
  m_serv_name = serv_name;
}
