#ifndef UTIL_HPP
#define UTIL_HPP
#include <string>
#include <vector>

class Util {
  public:
    static std::string itoa(int value, int base);
    static std::vector<std::string> split(std::string str, char delimiter);
};
#endif