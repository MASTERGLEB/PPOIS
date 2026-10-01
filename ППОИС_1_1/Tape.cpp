#include "Tape.h"
Tape::Tape() : data("") {}
Tape::Tape(const std::string& s) : data(s) {}
std::string Tape::getData() const { return data; }
void Tape::setData(const std::string& s) { data = s; }
void Tape::load(std::istream& is) {
    std::getline(is, data);
}
bool Tape::replaceFirst(const std::string& from, const std::string& to) {
    if (from.empty()) {
        return false;
    }
    size_t pos = data.find(from);
    if (pos == std::string::npos) {
        return false;
    }
    data.replace(pos, from.length(), to);
    return true;
}
std::ostream& operator<<(std::ostream& os, const Tape& t) {
    os << t.data;
    return os;
}