#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Specify the file name
    std::string filename = "output.txt";

    // Create an ofstream object to open the file
    std::ofstream outfile;

    // Open the file
    outfile.open(filename);

    // Check if the file opened successfully
    if (!outfile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    // Write some data to the file
    outfile << "Hello, world!" << std::endl;
    outfile << "This is a simple file writing example." << std::endl;

    // Close the file
    outfile.close();

    std::cout << "Data written to " << filename << " successfully." << std::endl;

    return 0;
}

