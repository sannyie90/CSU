// Program Name: User Input and Reversal
// Author: Mannan Ahmad
// Date: 03/16/2025

#include <iostream>  // Include for input/output operations
#include <fstream>   // Include for file handling
#include <string>    // Include for string operations
#include <algorithm> // Include for reverse function

using namespace std;

int main() {
    // Declare a string variable to store user input
    string userInput;

    // Define file names
    string filename = "CSC450_CT5_mod5.txt"; // This file stores user input
    string reversedFilename = "CSC450-mod5-reverse.txt"; // This file stores reversed content

    // Step 1: Open the file in append mode to preserve existing data
    ofstream outFile(filename, ios::out | ios::app);

    // Check if the file opened successfully
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1; // Exit with an error code
    }

    // Step 2: Prompt the user to enter text
    cout << "Enter text to append to the file: ";
    getline(cin, userInput); // Read full line input from user

    // Step 3: Append user input to the file
    outFile << userInput << endl;

    // Step 4: Close the file after writing
    outFile.close();

    // Step 5: Open the file in read mode to read its content
    ifstream inFile(filename);

    // Check if the file opened successfully
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1; // Exit with an error code
    }

    // Step 6: Read the entire file content into a string
    string fileContent = "", line;

    while (getline(inFile, line)) {
        fileContent += line + "\n"; // Store everything
    }

    // Step 7: Close the input file after reading
    inFile.close();

    // Step 8: Reverse the entire file content
    reverse(fileContent.begin(), fileContent.end());

    // Step 9: Open the new file to store reversed content
    ofstream revFile(reversedFilename);

    // Check if the file opened successfully
    if (!revFile) {
        cerr << "Error opening reverse file for writing!" << endl;
        return 1; // Exit with an error code
    }

    // Step 10: Write the fully reversed content into the new file
    revFile << fileContent;

    // Step 11: Close the reversed file after writing
    revFile.close();

    // Step 12: Notify the user of successful execution
    cout << "Data successfully appended to " << filename << endl;
    cout << "Reversed content saved in " << reversedFilename << endl;

    return 0; // Exit successfully
}
