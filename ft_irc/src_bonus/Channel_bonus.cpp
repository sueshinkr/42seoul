#include "Channel_bonus.hpp"

/*==============================
-----------generator------------
===============================*/

Channel::Channel() {}

Channel::Channel(std::string channel_name, Client &clnt)
    : m_channel_name(channel_name), m_notice_flag(false) {
  add_client(clnt);
}

/*==============================
---------public_function--------
===============================*/

void Channel::sendMsg(std::string msg) {
  for (std::vector<Client *>::iterator iter = m_clients.begin();
       iter != m_clients.end(); iter++) {
    (*iter)->sendMsg(msg);
  }
}

void Channel::sendMsg(std::string msg, std::string nickname) {
  for (std::vector<Client *>::iterator iter = m_clients.begin();
       iter != m_clients.end(); iter++) {

    if ((*iter)->get_m_nickname() != nickname) {
      (*iter)->sendMsg(msg);
    }
  }
}

void Channel::sendToMsg(std::string msg, std::string nickname) {

	Client &clnt = get_m_client(nickname);
	clnt.sendMsg(msg);
}

void Channel::add_client(Client &clnt) {
  ChannelAuth *channel_auth = new ChannelAuth;
  m_name_to_client.insert(std::make_pair(clnt.get_m_nickname(),
                                         std::make_pair(&clnt, channel_auth)));
  m_clients.push_back(&clnt);
  clnt.set_m_channel(m_channel_name);
}

int Channel::get_numOfpeople(void) { return (m_clients.size()); }

/*==============================
----------get_function----------
===============================*/

std::string Channel::get_m_channel_name(void) const { return (m_channel_name); }

std::string Channel::get_m_password(void) const { return (m_password); }

bool Channel::get_m_notice_flag(void) const { return (m_notice_flag); }

int Channel::get_m_limit(void) const { return (m_limit); }

int Channel::get_m_oper_cnt(void) const { return (m_oper_cnt); }

Client &Channel::get_m_client(std::string nickname) {
  std::map<std::string, std::pair<Client *, ChannelAuth *> >::iterator iter =
      m_name_to_client.find(nickname);

  if (iter == m_name_to_client.end())
    throw std::out_of_range("");
  return (*(iter->second.first));
}

ChannelAuth &Channel::get_m_channelauth(std::string nickname) {
  std::map<std::string, std::pair<Client *, ChannelAuth *> >::iterator iter =
      m_name_to_client.find(nickname);

  if (iter == m_name_to_client.end())
    throw std::out_of_range("");
  return (*(iter->second.second));
}

std::vector<Client *> Channel::get_m_clients(void) { return (m_clients); }

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
  try {
    m_name_to_client[nickname] = std::make_pair(
        &get_m_client(prev_nickname), &get_m_channelauth(prev_nickname));
    m_name_to_client.erase(prev_nickname);
  } catch (const std::exception &e) {
    throw std::out_of_range("");
  }
}

void Channel::del_m_client(std::string nickname) {
  for (std::vector<Client *>::iterator iter = m_clients.begin();
       iter != m_clients.end(); iter++) {
    if ((*iter)->get_m_nickname() == nickname) {
      m_clients.erase(iter);
      break;
    }
  }
  for (std::map<std::string, std::pair<Client *, ChannelAuth *> >::iterator
           iter = m_name_to_client.begin();
       iter != m_name_to_client.end(); iter++) {
    if ((*iter).second.first->get_m_nickname() == nickname) {
      delete (*iter).second.second;
      m_name_to_client.erase(nickname);
      break;
    }
  }
}
