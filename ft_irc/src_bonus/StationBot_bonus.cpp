#include "StationBot_bonus.hpp"
#include "Exit_bonus.hpp"
#include "Util_bonus.hpp"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <cstdio>

std::string StationBot::toUrlEncoding(const std::string &s)
{
  const std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_.~";

  std::string res="";
  for(size_t i=0; i<s.length(); i++)
  {
      if (alpha.find_first_of(s[i]) != std::string::npos)
      {
          res.push_back(s[i]);
      }
      else
      {
          res.append("%");
          char buf[3];
          sprintf(buf, "%.2X", (unsigned char) s[i]);
          res.append(buf);
      }
  }
  return res;
}

std::vector<std::string> StationBot::send_data()
{
  std::string res = "";
  std::vector<std::string> returnVector;

  char buf[1024] = {0,};
  while (read(0, buf, 1024))
    res += buf;
  res.erase(res.find('\n'));

  if (res.find_first_of('=') == std::string::npos)
    return (returnVector);
  std::string chname = res.substr(0,res.find_first_of('='));
  res = res.substr(res.find_first_of('=') + 1);
  returnVector.push_back(chname);

  std::vector<std::string> params = Util::split(res, '#');
  if (params.size() == 0)
    return (returnVector);

  if (params.size() == 1 && params[0] == "Error")
  {
    returnVector.push_back(params[0]);
    return (returnVector);
  }

  for (std::vector<std::string>::iterator iter = params.begin(); iter != params.end(); iter++) {
    std::vector<std::string> tmp = Util::split(*iter, '@');
    if (tmp.size() != 5)
      continue;
    std::string line = "🚇";
    std::string subwayID = tmp[0];
    std::string trainLine = tmp[1];
    std::string arvMsg = tmp[2];
    std::string arvMsg2 = tmp[3];
    std::string exTime = tmp[4];
    if (subwayID == LINE1)
    {
      line += CLINE1;
      line += "1호선";
      line += trainLine;
      line += CRESET;
    }
    else if (subwayID == LINE2)
    {
      line += CLINE2;
      line += "2호선";
      line += trainLine;
      line += CRESET;
    }
    else if (subwayID == LINE3)
    {
      line += CLINE3;
      line += "3호선";
      line += trainLine;
      line += CRESET;
    }
    else if (subwayID == LINE4)
    {
      line += CLINE4;
      line += "4호선";
      line += trainLine;
      line += CRESET;
    }
    else if (subwayID == LINE5)
    {
      line += CLINE5;
      line += "5호선";
      line += trainLine;
      line += CRESET;      
    }
    else if (subwayID == LINE6)
    {
      line += CLINE6;
      line += "6호선";
      line += trainLine;
      line += CRESET;      
    }
    else if (subwayID == LINE7)
    {
      line += CLINE7;
      line += "7호선";
      line += trainLine;
      line += CRESET;      
    }
    else if (subwayID == LINE8)
    {
      line += CLINE8;
      line += "8호선";
      line += trainLine;
      line += CRESET;      
    }
    else if (subwayID == LINE9)
    {
      line += CLINE9;
      line += "9호선";
      line += trainLine;
      line += CRESET;      
    }
    else if (subwayID == JUNGANG)
    {
      line += CJUNGANG;
      line += "중앙선";
      line += trainLine;
      line += CRESET;      
    }
    else if (subwayID == GYEONGUI)
    {
      line += CGYEONGUI;
      line += "경의중앙선";
      line += trainLine;
      line += CRESET;      
    }
    else if (subwayID == AIRPORT)
    {
      line += CAIRPORT;
      line += "공항철도";
      line += trainLine;
      line += CRESET;      
    }
    else if (subwayID == GYEONGCHUN)
    {
      line += CGYEONGCHUN;
      line += "경춘선";
      line += trainLine;
      line += CRESET;      
    }
    else if (subwayID == SUIN)
    {
      line += CSUIN;
      line += "수인분당선";
      line += trainLine;
      line += CRESET;      
    }
    else if (subwayID == SHINBUNDANG)
    {
      line += CSHINBUNDANG;
      line += "신분당선";
      line += trainLine;
      line += CRESET;      
    }
    else if (subwayID == UISINSEOL)
    {
      line += CUISINSEOL;
      line += "우이신설선";
      line += trainLine;
      line += CRESET;      
    }
    else
    {
      line += trainLine;
    }
    line += " : ";
    line += arvMsg;
    if (exTime != "0")
    {
      line += CRED;
      int time = atoi(exTime.c_str());
      if (time <= 60)
        line += "(곧 도착)";
      else
      {
        int miniute = time / 60;
        line += "(";
        line += Util::itoa(miniute, 10);;
        line += "분 후 도착";
        line += ")";
      }
      line += CRESET;
    }
    line += CYELLOW;
    line += " | 현위치 : ";
    line += arvMsg2;
    line += "|";
    line += CRESET;
    returnVector.push_back(line);
  }
  return (returnVector);
}


void StationBot::get_data(std::string &station, std::string &channelName)
{
  pid_t pid;
  int fd[2];

  if (pipe(fd) < 0)
    Exit::NormalExit();

  if ((pid = fork()) < 0)
    Exit::NormalExit();
  if (pid == 0)
  {
    std::string stationUrl = toUrlEncoding(station);
    dup2(fd[1], 1);
    close(fd[0]);
    close(fd[1]);
    execl("./src/get_data.sh", "./src/get_data.sh", stationUrl.c_str(), channelName.c_str(), NULL);
    std::cout << channelName << "=Error";
    exit(1);
  }
  else
  {
    dup2(fd[0], 0);
    close(fd[1]);
    close(fd[0]);
  }
}