#include "Machine.h"
#include <fstream>
#include <stdexcept>
Machine::Machine() {}
Machine::Machine(const Tape& t, const Program& p) : tape(t), program(p) {}
Tape& Machine::getTape() { return tape; }
const Tape& Machine::getTape() const { return tape; }
Program& Machine::getProgram() { return program; }
const Program& Machine::getProgram() const { return program; }
void Machine::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        throw std::runtime_error("Cannot open file");
    }

    tape.load(file);
    program.load(file);
}

void Machine::run(bool log) {
    program.run(tape, log);
}