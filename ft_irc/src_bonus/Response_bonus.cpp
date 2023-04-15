#include "Response_bonus.hpp"

#include <iostream>

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

std::string Response::rplWhoisChannels(std::string requestNickname,
                                       std::string nickname,
                                       std::string chlist) {
  return (":" + m_serv_name + " 319 " + requestNickname + " " + nickname +
          " :" + chlist + "\r\n");
}

std::string Response::rplEndofWhois(std::string requestNickname,
                                    std::string nickname) {
  return (":" + m_serv_name + " 318 " + requestNickname + " " + nickname +
          "\r\n");
}

std::string Response::rplUModeIs(std::string nickname, std::string mode) {
  return (":" + m_serv_name + " 221 " + nickname + " :" + mode + "\r\n");
}

std::string Response::rplChannelModeIs(std::string channelname,
                                       std::string mode, std::string params) {
  return (":" + m_serv_name + " 324 * " + channelname + " " + mode + " " +
          params + " \r\n");
}

std::string Response::rplYoureOper(void) {
  return (":" + m_serv_name + " 381 OPER :You are now an IRC operator\r\n");
}

std::string Response::rplKillDone(std::string nickname, std::string target) {
  return (":" + m_serv_name + " 361 " + nickname + " " + target +
          " has been killed\r\n");
}

std::string Response::rplNamReply(std::string channel,
                                  std::vector<std::string> users) {
  std::string nick;

  for (size_t i = 0; i < users.size(); i++) {
    nick += users[i];
    nick += " ";
  }
  return (":" + m_serv_name + " 353 * = " + channel + " :" + nick + "\r\n");
}

std::string Response::rplEndOfNames(std::string channel) {
  return (":" + m_serv_name + " 366 * " + channel + " :End of NAMES list\r\n");
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
  return (":" + m_serv_name + " 401 * " + cmd + " :" + nickname + "\r\n");
}

std::string Response::errUsersDontMatch(void) {
  return (":" + m_serv_name +
          " 502 Mode :Cannot set/get mode for other users\r\n");
}

std::string Response::errUmodeUnknownFlag(void) {
  return (":" + m_serv_name + " 501 MODE :Unknown MODE flag\r\n");
}

std::string Response::errUnknownMode(std::string mode,
                                     std::string channel_name) {
  return (":" + m_serv_name + " 472 * " + mode +
          " :is unknown mode char to me for " + channel_name + "\r\n");
}

std::string Response::errChaNoPrivsNeeded(std::string channel_name) {
  return (":" + m_serv_name + " 482 " + channel_name +
          " :You're not channel operator\r\n");
}

std::string Response::errUserNotInChannel(std::string nick,
                                          std::string channel_name) {
  return (":" + m_serv_name + " 441 * " + nick + " " + channel_name +
          " :They aren't on that channel\r\n");
}

std::string Response::errNoPrivileges(void) {
  return (":" + m_serv_name + " 481" + " : Permission Denied\r\n");
}

std::string Response::errPassWDMismatch(void) {
  return (":" + m_serv_name + " 464 * :Password incorrect\r\n");
}

std::string Response::errChannelIsFull(std::string channel_name) {
  return (":" + m_serv_name + " 471 * " + channel_name +
          " :Cannot join channel\r\n");
}

std::string Response::errBadChannelKey(std::string channel_name) {
  return (":" + m_serv_name + " 475 * " + channel_name +
          " :Cannot join channel (+k)\r\n");
}

std::string Response::errNotOnChannel(std::string channel_name) {
  return (":" + m_serv_name + " 442 " + channel_name +
          " :You're not on that channel\r\n");
}

std::string Response::errNoSuchChannel(std::string cmd,
                                       std::string channel_name) {
  return (":" + m_serv_name + " 403 " + cmd + " :" + channel_name + "\r\n");
}

std::string Response::errCannotSendToChan(std::string channel_name) {
  return (":" + m_serv_name + " 404 " + channel_name +
          " :Cannot send to channel\r\n");
}

std::string Response::errErroneusNickname(std::string nickname) {
  return (":" + m_serv_name + " 432 " + nickname + " :Erroneous nickname\r\n");
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

std::string Response::setChMode(std::string nickname, std::string username,
                                std::string hostname, std::string channelname,
                                std::string mode) {
  return (":" + nickname + "!" + username + "@" + hostname + " MODE " +
          channelname + " " + mode + "\r\n");
}

std::string Response::noticeKill(std::string nickname, std::string username,
                                 std::string hostname, std::string kill_msg) {
  return (":" + nickname + "!" + username + "@" + hostname + " KILL" + " * " +
          kill_msg + "\r\n");
}

std::string Response::noticeQuit(std::string nickname, std::string username,
                                 std::string hostname, std::string quit_msg) {
  return (":" + nickname + "!" + username + "@" + hostname + " QUIT " +
          quit_msg + "\r\n");
}

std::string Response::joinChannel(std::string nickname, std::string username,
                                  std::string hostname,
                                  std::string channelname) {
  return (":" + nickname + "!" + username + "@" + hostname + " JOIN " +
          channelname + "\r\n");
}

std::string Response::partChannel(std::string nickname, std::string username,
                                  std::string hostname, std::string channelname,
                                  std::string msg) {
  return (":" + nickname + "!" + username + "@" + hostname + " PART " +
          channelname + " :" + msg + "\r\n");
}

std::string Response::privMsg(std::string nickname, std::string username,
                              std::string hostname, std::string target,
                              std::string msg) {
  return (":" + nickname + "!" + username + "@" + hostname + " PRIVMSG " +
          target + " " + msg + "\r\n");
}

std::string Response::noticeMsg(std::string nickname, std::string username,
                                std::string hostname, std::string target,
                                std::string msg) {
  return (":" + nickname + "!" + username + "@" + hostname + " NOTICE " +
          target + " :" + msg + "\r\n");
}

std::string Response::kickMsg(std::string nickname, std::string username,
                              std::string hostname, std::string channelname,
                              std::string user, std::string comment) {
  return (":" + nickname + "!" + username + "@" + hostname + " KICK " +
          channelname + " " + user + " :" + comment + "\r\n");
}

/*==============================
----------set_function----------
===============================*/

void Response::set_m_serv_name(std::string serv_name) {
  m_serv_name = serv_name;
}
