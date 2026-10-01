#pragma once
#include <string>
#include <iostream>
class Rule {
private:
    std::string left;
    std::string right;
    bool terminal;
public:
    Rule();
    Rule(const std::string& l, const std::string& r, bool t = false);
    std::string getLeft() const;
    std::string getRight() const;
    bool isTerminal() const;
    void setLeft(const std::string& l);
    void setRight(const std::string& r);
    void setTerminal(bool t);
    friend std::ostream& operator<<(std::ostream& os, const Rule& r);
    friend std::istream& operator>>(std::istream& is, Rule& r);
};