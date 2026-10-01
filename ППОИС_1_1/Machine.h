#pragma once
#include <string>
#include "Tape.h"
#include "Program.h"
class Machine {
private:
    Tape tape;
    Program program;
public:
    Machine();
    Machine(const Tape& t, const Program& p);
    Tape& getTape();
    const Tape& getTape() const;
    Program& getProgram();
    const Program& getProgram() const;
    void loadFromFile(const std::string& filename);
    void run(bool log = false);
};