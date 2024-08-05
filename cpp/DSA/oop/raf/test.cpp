#include <iostream>
#include <fstream>

using namespace std;

const std::string filename = "state.txt";

void saveState(int state) {
    ofstream file(filename);
    if (file.is_open()) {
        file << state;
        file.close();
    } else {
        std::cerr << "Unable to open file for writing.\n";
    }
}

int loadState() {
    ifstream ip(filename);
    int state = 0;
    if (ip.is_open()) {
        ip >> state;
        ip.close();
    } else {
        std::cerr << "Unable to open file for reading. Starting from state 0.\n";
    }
    return state;
}

int main() {
    int state = loadState();

    std::cout << "Current state: " << state << std::endl;

    // Perform some calculations
    for (int i = 0; i < 5; ++i) {
        state += 1;
        std::cout << "State: " << state << std::endl;
    }

    // Save the current state to file
    saveState(state);

    return 0;
}
