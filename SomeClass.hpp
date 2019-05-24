#pragma once

#include <chrono>
#include <string>

#include <sstream>
#include <iomanip>


//using T = std::chrono::time_point<std::chrono::system_clock>;
template <class T>
class Property {
  public:
    explicit Property(T& r) : reference{r} {}


    Property& operator=(const std::string& s) {
        std::tm tm = {};
        std::stringstream ss(s);
        ss >> std::get_time(&tm, "%b %d %Y %H:%M:%S");
        reference = std::chrono::system_clock::from_time_t(std::mktime(&tm));
        return *this;
    }

    Property& operator=(
        const std::chrono::time_point<std::chrono::system_clock>& tp) {
        reference = tp;
        return *this;
    }

    Property& operator=(const unsigned& secondsSinceEpoch) {
        std::chrono::seconds duration(secondsSinceEpoch);
        std::chrono::time_point<std::chrono::system_clock> dt(duration);
        reference = dt;
        return *this;
    }


    explicit operator std::string() {
        const std::time_t t = std::chrono::system_clock::to_time_t(reference);
        char s[1000];
        struct tm* tm = std::localtime(&t);
        strftime(s, 1000, "%b %d %Y %H:%M:%S", tm);
        return s;
    }

    /*explicit*/ operator std::chrono::time_point<std::chrono::system_clock>() {
        const auto secondsSinceEpoch =
            std::chrono::time_point_cast<std::chrono::seconds>(reference);
        return secondsSinceEpoch;
    }

    explicit operator unsigned() {
        const auto epoch = reference.time_since_epoch();
        const auto value = std::chrono::duration_cast<std::chrono::seconds>(epoch);
        return value.count(); // warning C4244: 'return': conversion from '_Rep' to 'unsigned int', possible loss of data
    }

  private:
    T& reference;
};

class SomeClass {
  private:
    std::chrono::time_point<std::chrono::system_clock> impl;
    // static decltype(impl) fromString(const std::string&);

  public:
    //Property property{impl};
    Property<decltype(impl)> property{impl};
};
