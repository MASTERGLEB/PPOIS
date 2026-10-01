#include "Machine.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <file> [-log]\n";
        return 1;
    }
    bool log = false;
    if (argc >= 3 && std::string(argv[2]) == "-log") {
        log = true;
    }
    try {
        Machine machine;
        machine.loadFromFile(argv[1]);
        machine.run(log);
        std::cout << machine.getTape() << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
    return 0;
}