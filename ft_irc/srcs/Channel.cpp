#include "Channel.hpp"

/*==============================
-----------generator------------
===============================*/

Channel::Channel() {}

Channel::Channel(std::string channel_name, Client clnt)
    : m_channel_name(channel_name) {
  ChannelAuth channel_auth;
  m_clients[clnt.get_m_nickname()] = std::make_pair(clnt, channel_auth);
}

/*==============================
---------public_function--------
===============================*/

int Channel::sendMsg(std::string msg, int clnt_fd) {
  if (send(clnt_fd, msg.c_str(), sizeof(msg), 0) == -1) return (ERR);
  return (PASS);
}

void Channel::add_client(Client clnt) {
  ChannelAuth channel_auth;
  m_clients.insert(std::make_pair(clnt.get_m_nickname(),
                                  std::make_pair(clnt, channel_auth)));
}

/*==============================
----------get_function----------
===============================*/

std::string Channel::get_m_channel_name(void) const { return (m_channel_name); }

std::string Channel::get_m_password(void) const { return (m_password); }

bool Channel::get_m_notice_flag(void) const { return (m_notice_flag); }

int Channel::get_m_limit(void) const { return (m_limit); }

int Channel::get_m_oper_cnt(void) const { return (m_oper_cnt); }

Client Channel::get_m_client(std::string nickname) const {
  return (m_clients.find(nickname)->second.first);
}

ChannelAuth Channel::get_m_channelauth(std::string nickname) const {
  return (m_clients.find(nickname)->second.second);
}

/*==============================
----------set_function----------
===============================*/

void Channel::set_m_channel_name(std::string channel_name) {
  m_channel_name = channel_name;
}

void Channel::set_m_password(std::string password) { m_password = password; }

void Channel::set_m_notice_flag(bool flag) { m_notice_flag = flag; }

void Channel::set_m_limit(int limit) { m_limit = limit; }

void Channel::set_m_oper_cnt(int oper_cnt) { m_oper_cnt = oper_cnt; }

