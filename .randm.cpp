#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

string generatePassword(int length, bool useUpper, bool useLower, bool useDigits, bool useSpecial) {
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string digits = "0123456789";
    const string special = "!@#$%^&*()-_=+[{]}|;:',<.>/?`~";

    string allChars = "";
    if (useUpper) allChars += upper;
    if (useLower) allChars += lower;
    if (useDigits) allChars += digits;
    if (useSpecial) allChars += special;

    if (allChars.empty()) {
        return "Error: No character sets selected!";
    }

    string password = "";
    for (int i = 0; i < length; ++i) {
        int randIndex = rand() % allChars.length();
        password += allChars[randIndex];
    }

    return password;
}

bool isYes(char choice) {
    return tolower(choice) == 'y';
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random generator

    int length;
    char upperChoice, lowerChoice, digitChoice, specialChoice;

    cout << "==== SIMPLE PASSWORD GENERATOR ====\n";

    // Get password length with input validation
    do {
        cout << "Enter password length (min 8, max 64): ";
        cin >> length;
        if (length < 8 || length > 64) {
            cout << "Invalid length. Please enter a value between 8 and 64.\n";
        }
    } while (length < 8 || length > 64);

    // Character set preferences
    cout << "Include uppercase letters? (y/n): ";
    cin >> upperChoice;

    cout << "Include lowercase letters? (y/n): ";
    cin >> lowerChoice;

    cout << "Include digits? (y/n): ";
    cin >> digitChoice;

    cout << "Include special characters? (y/n): ";
    cin >> specialChoice;

    // Generate password
    string password = generatePassword(
        length,
        isYes(upperChoice),
        isYes(lowerChoice),
        isYes(digitChoice),
        isYes(specialChoice)
    );

    cout << "\nGenerated Password: " << password << endl;

    return 0;
}


