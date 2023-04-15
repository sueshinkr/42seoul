#include "ChannelAuth_bonus.hpp"

/*==============================
-----------generator------------
===============================*/

ChannelAuth::ChannelAuth() : m_oper(false), m_voice(true) {}

/*==============================
----------get_function----------
===============================*/

bool ChannelAuth::get_m_oper(void) const { return (m_oper); }
bool ChannelAuth::get_m_voice(void) const { return (m_voice); }

/*==============================
----------set_function----------
===============================*/

void ChannelAuth::set_m_oper(bool oper) { m_oper = oper; }
void ChannelAuth::set_m_voice(bool voice) { m_voice = voice; }