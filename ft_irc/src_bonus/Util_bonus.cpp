#include "Util_bonus.hpp"

std::vector<std::string> Util::split(std::string str, char limiter) {
    std::vector<std::string> tokens;
    std::string token;
    size_t pos = 0;
    while ((pos = str.find(limiter)) != std::string::npos) {
        token = str.substr(0, pos);
        tokens.push_back(token);
        str.erase(0, pos + 1);
    }
    if (str.size() > 0)
        tokens.push_back(str);
    return tokens;
}

std::string Util::itoa(int value, int base) {
    std::string result;
    bool ne = false;
    if (value < 0) {
        ne = true;
        value = -value;
    }
    do {
        char digit = value % base;
        if (digit < 10) {
            digit += '0';
        } else {
            digit += 'a' - 10;
        }
        result = digit + result;
        value /= base;
    } while (value > 0);
    if (ne) {
        result = "-" + result;
    }
    return result;
}