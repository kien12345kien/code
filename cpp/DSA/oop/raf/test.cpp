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
    ifstream file(filename);
    int state = 0;
    if (file.is_open()) {
        file >> state;
        file.close();
    } else {
        std::cerr << "Unable to open file for reading. Starting from state 0.\n";
    }
    return state;
}

int main() {
    int state = loadState();
    int n;
    cin >> n;

    std::cout << "Current state: " << state << std::endl;

    // Perform some calculations
    for (int i = 0; i < n; ++i) {
        state += 1;
        std::cout << "State: " << state << std::endl;
    }

    // Save the current state to file
    saveState(state);

    return 0;
}
