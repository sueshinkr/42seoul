#include <string>
#include <vector>

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
  static std::string rplChannelModeIs(std::string channelname, std::string mode,
                                      std::string params);
  static std::string rplYoureOper(void);
  static std::string rplKillDone(std::string nickname, std::string target);
  static std::string rplNamReply(std::string channel,
                                 std::vector<std::string> users);
  static std::string rplEndOfNames(std::string channel);

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
  static std::string errChannelIsFull(std::string channel_name);
  static std::string errBadChannelKey(std::string channel_name);
  static std::string errNotOnChannel(std::string channel_name);
  static std::string errNoSuchChannel(std::string cmd,
                                      std::string channel_name);
  static std::string errCannotSendToChan(std::string channel_name);
  static std::string errErroneusNickname(std::string nickname);

  static std::string noticeNick(std::string prevNickname, std::string nickname,
                                std::string username, std::string hostname);
  static std::string responsePong(void);
  static std::string setMode(std::string nickname, std::string username,
                             std::string hostname, std::string mode);

  static std::string setChMode(std::string nickname, std::string username,
                               std::string hostname, std::string channelname,
                               std::string mode);
  static std::string noticeKill(std::string nickname, std::string username,
                                std::string hostname,
                                std::string kill_msg = "You Killed");
  static std::string noticeQuit(std::string nickname, std::string username,
                                std::string hostname,
                                std::string quit_msg = "leaving");
  static std::string joinChannel(std::string nickname, std::string username,
                                 std::string hostname, std::string channelname);
  static std::string partChannel(std::string nickname, std::string username,
                                 std::string hostname, std::string channelname,
                                 std::string msg = "I lost");
  static std::string privMsg(std::string nickname, std::string username,
                             std::string hostname, std::string target,
                             std::string msg);
  static std::string noticeMsg(std::string nickname, std::string username,
                               std::string hostname, std::string target,
                               std::string msg);
  static std::string kickMsg(std::string nickname, std::string username,
                             std::string hostname, std::string channelname,
                             std::string user,
                             std::string comment = "You Kicked");

  static void set_m_serv_name(std::string serv_name);
};
