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

std::string Response::rplWhoisServer(std::string requestNickname,
                                     std::string nickname) {
  return (":" + m_serv_name + " 312 " + requestNickname + " " + nickname +
          " testServer :version 1.0\r\n");
}

// 채널관련 동작 완성후 확인해봐야됨
std::string Response::rplWhoisChannels(std::string requestNickname,
                                       std::string nickname,
                                       std::string chlist) {
  return (":" + m_serv_name + " 319 " + nickname + " : " + chlist +
          "\r\n");  //:is an IRC Operator\r\n");
}

std::string Response::rplEndofWhois(std::string requestNickname,
                                    std::string nickname) {
  return (":" + m_serv_name + " 318 " + requestNickname + " " + nickname +
          "\r\n");
}

std::string Response::rplUModeIs(std::string nickname, std::string mode) {
  return (":" + m_serv_name + " 221 " + nickname + " :" + mode + "\r\n");
}

std::string Response::rplYoureOper(void) {
  return (":" + m_serv_name + "381 :You are now an IRC operator\r\n");
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

std::string Response::errUsersDontMatch(void) {
  return (":" + m_serv_name +
          " 502 Mode :Cannot set/get mode for other users\r\n");
}

std::string Response::errUmodeUnknownFlag(void) {
  return (":" + m_serv_name + " 501 Mode :Unknown MODE flag\r\n");
}

std::string Response::errUnknownMode(std::string mode,
                                     std::string channel_name) {
  return (":" + m_serv_name + " 472 " + mode +
          " :is unknown mode char to me for " + channel_name + "\r\n");
}

std::string Response::errChaNoPrivsNeeded(std::string channel_name) {
  return (":" + m_serv_name + " 482 " + channel_name +
          " :You're not channel operator\r\n");
}

std::string Response::errUserNotInChannel(std::string nick,
                                          std::string channel_name) {
  return (":" + m_serv_name + " 441 " + nick + " " + channel_name +
          " :They aren't on that channel\r\n");
}

std::string Response::errNoPrivileges(void) {
  return (":" + m_serv_name + " 481" + " : Permission Denied\r\n");
}

std::string Response::errPassWDMismatch(void) {
  return (":" + m_serv_name + "464 :Password incorrect\r\n");
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

std::string Response::setMode(std::string nickname, std::string username,
                              std::string hostname, std::string mode) {
  return (":" + nickname + "!" + username + "@" + hostname + " MODE " +
          nickname + " :" + mode + "\r\n");
}

/*==============================
----------set_function----------
===============================*/

void Response::set_m_serv_name(std::string serv_name) {
  m_serv_name = serv_name;
}
