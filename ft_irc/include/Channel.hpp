#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>
#include <map>
#include <string>

#include "ChannelAuth.hpp"
#include "Client.hpp"

class Channel {
 private:
  std::string m_channel_name;
  std::string m_password;
  bool m_notice_flag;
  int m_limit;
  int m_oper_cnt;
  std::map<std::string, std::pair<Client, ChannelAuth> > m_name_to_client;
  std::vector<Client> m_clients;

 public:
  Channel();
  Channel(std::string channel_name, Client &clnt);

  int sendMsg(std::string msg);
  void add_client(Client &clnt);

  std::string get_m_channel_name(void) const;
  std::string get_m_password(void) const;
  bool get_m_notice_flag(void) const;
  int get_m_limit(void) const;
  int get_m_oper_cnt(void) const;
  Client get_m_client(std::string nickname) const;
  ChannelAuth get_m_channelauth(std::string nickname) const;

  void set_m_channel_name(std::string channel_name);
  void set_m_password(std::string password);
  void set_m_notice_flag(bool flag);
  void set_m_limit(int limit);
  void set_m_oper_cnt(int oper_cnt);

  void del_m_client(std::string nickname);

  void change_m_name_to_client(std::string prev_nickname, std::string nickname);
};

#endif
