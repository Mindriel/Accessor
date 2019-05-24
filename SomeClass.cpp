#include "SomeClass.hpp"

#include <sstream>
#include <iomanip>


/*
std::chrono::time_point<std::chrono::system_clock> SomeClass::fromString(const std::string& s) {
    std::tm tm = {};
    std::stringstream ss(s);
    ss >> std::get_time(&tm, "%b %d %Y %H:%M:%S");
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}
*/
