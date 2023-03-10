#include "Channel.hpp"

/*==============================
-----------generator------------
===============================*/

Channel::Channel() {}

Channel::Channel(std::string channel_name, Client &clnt)
    : m_channel_name(channel_name) {
  ChannelAuth channel_auth;
  m_name_to_client[clnt.get_m_nickname()] = std::make_pair(clnt, channel_auth);
  m_clients.push_back(clnt);
}

/*==============================
---------public_function--------
===============================*/

int Channel::sendMsg(std::string msg) {
  for (std::vector<Client>::iterator iter = m_clients.begin();
       iter != m_clients.end(); iter++) {
    if (send((*iter).get_m_clnt_fd(), msg.c_str(), sizeof(msg), 0) == -1)
      return (ERR);
  }
  return (PASS);
}

void Channel::add_client(Client &clnt) {
  ChannelAuth channel_auth;
  m_name_to_client.insert(std::make_pair(clnt.get_m_nickname(),
                                         std::make_pair(clnt, channel_auth)));
  m_clients.push_back(clnt);
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
  return (m_name_to_client.find(nickname)->second.first);
}

ChannelAuth Channel::get_m_channelauth(std::string nickname) const {
  return (m_name_to_client.find(nickname)->second.second);
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

void Channel::change_m_name_to_client(std::string prev_nickname,
                                      std::string nickname) {
  m_name_to_client[nickname] = std::make_pair(get_m_client(prev_nickname),
                                              get_m_channelauth(prev_nickname));
  m_name_to_client.erase(prev_nickname);
}
