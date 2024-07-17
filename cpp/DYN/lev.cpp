#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to calculate the Levenshtein distance recursively
int lev(string a, string b, int i, int j) {
    // Base cases
    if (i == 0) return j;
    if (j == 0) return i;

    // If last characters are the same, ignore last character and recur for remaining string
    if (a[i - 1] == b[j - 1])
        return lev(a, b, i - 1, j - 1);

    // If last characters are different, consider all possibilities and find the minimum
    return 1 + min({lev(a, b, i - 1, j), lev(a, b, i, j - 1), lev(a, b, i - 1, j - 1)});
}

int main() {
    string a = "kitten";
    string b = "sitting";

    int distance = lev(a, b, a.length(), b.length());

    cout << "The Levenshtein distance between \"" << a << "\" and \"" << b << "\" is " << distance << "." << endl;

    return 0;
}
