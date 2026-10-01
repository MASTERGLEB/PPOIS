#include "Rule.h"
Rule::Rule() : left(""), right(""), terminal(false) {}
Rule::Rule(const std::string& l, const std::string& r, bool t)
    : left(l), right(r), terminal(t) {
}
std::string Rule::getLeft() const { return left; }
std::string Rule::getRight() const { return right; }
bool Rule::isTerminal() const { return terminal; }
void Rule::setLeft(const std::string& l) { left = l; }
void Rule::setRight(const std::string& r) { right = r; }
void Rule::setTerminal(bool t) { terminal = t; }
std::ostream& operator<<(std::ostream& os, const Rule& r) {
    os << r.left << "->";
    if (r.terminal) {
        os << ".";
    }
    os << r.right;
    return os;
}
std::istream& operator>>(std::istream& is, Rule& r) {
    std::string line;
    std::getline(is, line);
    size_t pos = line.find("->");
    if (pos == std::string::npos) {
        is.setstate(std::ios::failbit);
        return is;
    }
    r.left = line.substr(0, pos);
    r.right = line.substr(pos + 2);
    r.terminal = false;
    if (!r.right.empty() && r.right[0] == '.') {
        r.terminal = true;
        r.right = r.right.substr(1);
    }
    return is;
}