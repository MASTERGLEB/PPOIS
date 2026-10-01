#include "Program.h"
Program::Program() {}
void Program::load(std::istream& is) {
    rules.clear();
    std::string line;
    while (std::getline(is, line)) {
        if (line.empty()) {
            continue;
        }
        size_t pos = line.find("->");
        if (pos == std::string::npos) {
            continue;
        }
        std::string left = line.substr(0, pos);
        std::string right = line.substr(pos + 2);
        bool terminal = false;
        if (!right.empty() && right[0] == '.') {
            terminal = true;
            right = right.substr(1);
        }
        rules.push_back(Rule(left, right, terminal));
    }
}
void Program::addRule(const Rule& r) {
    rules.push_back(r);
}
void Program::removeRule(size_t index) {
    if (index < rules.size()) {
        rules.erase(rules.begin() + index);
    }
}
void Program::clear() {
    rules.clear();
}
size_t Program::size() const {
    return rules.size();
}
Rule Program::getRule(size_t index) const {
    return rules[index];
}
void Program::print(std::ostream& os) const {
    for (size_t i = 0; i < rules.size(); ++i) {
        os << i << ": " << rules[i] << "\n";
    }
}
int Program::step(Tape& tape) const {
    for (size_t i = 0; i < rules.size(); ++i) {
        const Rule& r = rules[i];
        if (tape.replaceFirst(r.getLeft(), r.getRight())) {
            return r.isTerminal() ? 2 : 1;
        }
    }

    return 0;
}
void Program::run(Tape& tape, bool log) const {
    while (true) {
        int res = step(tape);
        if (log) {
            std::cout << tape << "\n";
        }
        if (res == 0 || res == 2) {
            break;
        }
    }
}