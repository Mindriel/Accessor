#include <iostream>
#include <string>
#include <cassert>


#include "SomeClass.hpp"
int main(int argc, char** argv) {
    std::cout << "Hello, World!" << std::endl;

    {
        SomeClass s;
        {
            const auto alwaysWorks = (std::chrono::time_point<std::chrono::system_clock>)s.property;
            const std::chrono::time_point<std::chrono::system_clock> castCannotBeExplicit = s.property;
        }
        std::cout << " -- 1 -- " << std::endl;
        std::cout << (std::string)s.property << std::endl;
        std::cout << (unsigned)s.property << std::endl;
        assert((std::string)s.property == "Jan 01 1970 01:00:00");
        assert((unsigned)s.property == 0);

        s.property = "Jan 9 2014 12:35:34";
        std::cout << " -- 2 -- " << std::endl;
        std::cout << (std::string)s.property << std::endl;
        std::cout << (unsigned)s.property << std::endl;
        assert((std::string)s.property == "Jan 09 2014 12:35:34");
        assert((unsigned)s.property == 1389267334);

        s.property = std::chrono::time_point<std::chrono::system_clock>{};
        std::cout << " -- 3 -- " << std::endl;
        std::cout << (std::string)s.property << std::endl;
        std::cout << (unsigned)s.property << std::endl;
        assert((std::string)s.property == "Jan 01 1970 01:00:00");
        assert((unsigned)s.property == 0);

        s.property = 10;
        std::cout << " -- 4 -- " << std::endl;
        std::cout << (std::string)s.property << std::endl;
        std::cout << (unsigned)s.property << std::endl;
        assert((std::string)s.property == "Jan 01 1970 01:00:10");
        assert((unsigned)s.property == 10);

        //std::cout << (int)s.property << std::endl;
    }

    std::cout << "Bye." << std::endl;
    return 0;
}


#include "Simple.hpp"
int main_simple(int argc, char** argv) {
    std::cout << "Hello, World!" << std::endl;

    {
        Simple s{"Hello"};
        std::cout << s << std::endl;
        // s.value = "s";
        // s.reader = "s";
        s.writer = "s";
        std::cout << s << std::endl;
    }

    {
        const std::string str{"boo"};
        Simple sr{str};
        std::cout << sr << std::endl;
        sr.writer = "s";
        std::cout << sr << std::endl;

        std::cout << str << std::endl;
    }

    std::cout << "Bye." << std::endl;
    return 0;
}
