// Program Name: Product Prices in a Store
// Author: Mannan Ahmad
// Date: 02/27/2025
// Description: This program asks for product names and integer prices individually, ensures valid input,
// dynamically stores them, displays values, and manages memory efficiently.

#include <iostream>
#include <limits>  // For input validation
#include <string>  // For storing product names
using namespace std;

// Function to validate integer input
void getValidInteger(int &value) {
    while (true) {
        cin >> value;

        // Check if input is valid
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Error: Invalid input. Please enter an integer price: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Remove leftover newline
            break; // Valid input, exit loop
        }
    }
}

int main() {
    // Declare variables for product names and prices
    string item1, item2, item3;
    int price1, price2, price3;

    // Ask for the first product name and price
    cout << "Enter the name of the first product: ";
    getline(cin, item1);
    cout << "Enter the price of " << item1 << " (must be an Integer): ";
    getValidInteger(price1);

    // Ask for the second product name and price
    cout << "\nEnter the name of the second product: ";
    getline(cin, item2);
    cout << "Enter the price of " << item2 << " (must be an Integer): ";
    getValidInteger(price2);

    // Ask for the third product name and price
    cout << "\nEnter the name of the third product: ";
    getline(cin, item3);
    cout << "Enter the price of " << item3 << " (must be an Integer): ";
    getValidInteger(price3);

    // Dynamically allocate memory for product prices
    int* ptrPrice1 = new int(price1);
    int* ptrPrice2 = new int(price2);
    int* ptrPrice3 = new int(price3);

    // Display product names and prices stored in stack memory
    cout << "\nProduct Information Stored in Stack Memory:\n";
    cout << item1 << ": $" << price1 << ", Address: " << &price1 << endl;
    cout << item2 << ": $" << price2 << ", Address: " << &price2 << endl;
    cout << item3 << ": $" << price3 << ", Address: " << &price3 << endl;

    // Display product prices stored in heap memory
    cout << "\nProduct Prices Stored in Heap Memory (Using Pointers):\n";
    cout << item1 << ": $" << *ptrPrice1 << ", Address: " << ptrPrice1 << endl;
    cout << item2 << ": $" << *ptrPrice2 << ", Address: " << ptrPrice2 << endl;
    cout << item3 << ": $" << *ptrPrice3 << ", Address: " << ptrPrice3 << endl;

    // Free dynamically allocated memory
    delete ptrPrice1;
    delete ptrPrice2;
    delete ptrPrice3;

    // Prevent dangling pointers
    ptrPrice1 = ptrPrice2 = ptrPrice3 = nullptr;

    return 0;
}
