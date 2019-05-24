#include "Simple.hpp"


Simple::Simple(const std::string& someString)
    : value{someString}, reader{value}, writer{value} {}

const std::string& Simple::getValue() const {
    return value;
}

std::ostream& operator<<(std::ostream& os, const Simple& s) {
    os << "Simple:\n";
    os << "  value : " << s.getValue() << "\n";
    os << "  reader: " << s.reader << "\n";
    os << "  writer: " << s.writer;
    return os;
}
