// Program Name: String Concatenation Console Application
// Author: Mannan Ahmad
// Date: 02/23/2025
// Description: This program takes two string inputs from the user three times, concatenates them, and prints the result.

#include <iostream>  // For input-output stream
#include <string>    // For string operations

using namespace std;

int main() {
    string string1, string2, result; // Declare string variables

    // Loop 3 times for varying string inputs
    for (int i = 1; i <= 3; i++) {
        cout << "Attempt " << i << ": Enter first string: ";
        getline(cin, string1);  // Get first string input

        cout << "Enter second string: ";
        getline(cin, string2);  // Get second string input

        result = string1 + " " + string2;  // Concatenate with a space in between

        cout << "Concatenated String: " << result << endl;  // Display output
        cout << "------------------------------" << endl;
    }

    return 0;  // End program
}
