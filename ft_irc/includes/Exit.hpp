#ifndef EXIT_HPP
#define EXIT_HPP

#include <signal.h>
#include <iostream>

#include "Server.hpp"

extern Server *g_serv;

class Exit {
 public:
  static void OnSignal(int sig) {
    std::cout << "==============" << std::endl;
    std::cout << "Server Quit!!" << std::endl;
    std::cout << "==============" << std::endl;
    signal(sig, SIG_IGN);
    delete g_serv;
    exit(1);
  }

  static void NormalExit() {
    std::cout << "==============" << std::endl;
    std::cout << "Server Quit!!" << std::endl;
    std::cout << "==============" << std::endl;
    delete g_serv;
    exit(1);
  }

  static void Handler() {
    std::cout << "===================================" << std::endl;
    std::cout << "Server Quit (Not Enough Memory))!!" << std::endl;
    std::cout << "===================================" << std::endl;
    delete g_serv;
    exit(1);
  }
};

#endif