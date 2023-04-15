#ifndef CHANNELAUTH_HPP
#define CHANNELAUTH_HPP

class ChannelAuth {
 private:
  bool m_oper;
  bool m_voice;

 public:
  ChannelAuth();

  void set_m_oper(bool oper);
  void set_m_voice(bool voice);

  bool get_m_oper(void) const;
  bool get_m_voice(void) const;
};

#endif
