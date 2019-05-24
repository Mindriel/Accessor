#pragma once

#include <ostream>
#include <string>


class Simple {
   public:
    explicit Simple(const std::string& someString);
    const std::string& getValue() const;

    const std::string& reader;
    std::string& writer;

   private:
    std::string value;
};

std::ostream& operator<<(std::ostream&, const Simple&);
