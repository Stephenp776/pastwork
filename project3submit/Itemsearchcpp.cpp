#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>

using namespace std;

void readFromFile(map<string, int>& itemFrequency, const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file " << filename << endl;
        exit(1);
    }
    string item;
    while (inputFile >> item) {
        itemFrequency[item]++;
    }
    inputFile.close();
}

void writeToFile(const map<string, int>& itemFrequency, const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open the file " << filename << endl;
        exit(1);
    }
    for (const auto& pair : itemFrequency) {
        outputFile << pair.first << " " << pair.second << endl;
    }
    outputFile.close();
}

void displayFrequency(const map<string, int>& itemFrequency) {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}

void displayHistogram(const map<string, int>& itemFrequency) {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    map<string, int> itemFrequency;
    string inputFile = "Text.txt";
    string outputFile = "frequency.dat";

    readFromFile(itemFrequency, inputFile);

    int choice;
    do {
        cout << "Menu Options:" << endl;
        cout << "1. Search for an item frequency" << endl;
        cout << "2. Display all items and their frequencies" << endl;
        cout << "3. Display histogram of items" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string item;
            cout << "Enter the item to search for: ";
            cin >> item;
            cout << item << " " << itemFrequency[item] << endl;
            break;
        }
        case 2: {
            displayFrequency(itemFrequency);
            break;
        }
        case 3: {
            displayHistogram(itemFrequency);
            break;
        }
        case 4: {
            writeToFile(itemFrequency, outputFile);
            cout << "Data written to " << outputFile << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != 4);

    return 0;
}
