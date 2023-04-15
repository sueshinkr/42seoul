#ifndef STATIONBOT_HPP
#define STATIONBOT_HPP

#include <iostream>
#include <vector>

#define LINE1 "1001"
#define LINE2 "1002"
#define LINE3 "1003"
#define LINE4 "1004"
#define LINE5 "1005"
#define LINE6 "1006"
#define LINE7 "1007"
#define LINE8 "1008"
#define LINE9 "1009"
#define JUNGANG "1061"
#define GYEONGUI "1063"
#define AIRPORT "1065"
#define GYEONGCHUN "1067"
#define SUIN "1075"
#define SHINBUNDANG "1077"
#define UISINSEOL "1092"

#define CLINE1 "\033[38;2;0;82;164m"
#define CLINE2 "\033[38;2;0;168;77m"
#define CLINE3 "\033[38;2;239;124;28m"
#define CLINE4 "\033[38;2;0;165;222m"
#define CLINE5 "\033[38;2;153;108;172m"
#define CLINE6 "\033[38;2;205;124;47m"
#define CLINE7 "\033[38;2;116;127;0m"
#define CLINE8 "\033[38;2;230;24;108m"
#define CLINE9 "\033[38;2;187;131;54m"
#define CJUNGANG "\033[38;2;119;196;163m"
#define CGYEONGUI "\033[38;2;119;196;163m"
#define CAIRPORT "\033[38;2;0;101;179m"
#define CGYEONGCHUN "\033[38;2;12;142;114m"
#define CSUIN "\033[38;2;245;162;0m"
#define CSHINBUNDANG "\033[38;2;212;0;59m"
#define CUISINSEOL "\033[38;2;183;196;82m"

#define CRED "\033[31m"
#define CYELLOW "\033[93m"
#define CRESET "\033[0m"

class StationBot {
  private:
    std::string toUrlEncoding(const std::string &s);
  public:
    void get_data(std::string &station, std::string &channelName);
    std::vector<std::string> send_data();
};

#endif