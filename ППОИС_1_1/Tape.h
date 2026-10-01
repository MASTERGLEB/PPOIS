#pragma once
#include <string>
#include <iostream>
class Tape {
private:
    std::string data;
public:
    Tape();
    Tape(const std::string& s);
    std::string getData() const;
    void setData(const std::string& s);
    void load(std::istream& is);
    bool replaceFirst(const std::string& from, const std::string& to);
    friend std::ostream& operator<<(std::ostream& os, const Tape& t);
};