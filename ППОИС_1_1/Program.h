#pragma once
#include <vector>
#include <iostream>
#include "Rule.h"
#include "Tape.h"
class Program {
private:
    std::vector<Rule> rules;
public:
    Program();
    void load(std::istream& is);
    void addRule(const Rule& r);
    void removeRule(size_t index);
    void clear();
    size_t size() const;
    Rule getRule(size_t index) const;
    void print(std::ostream& os) const;
    int step(Tape& tape) const;
    void run(Tape& tape, bool log = false) const;
};