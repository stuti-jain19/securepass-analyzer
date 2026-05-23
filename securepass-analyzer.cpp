#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void showHeader() {
    cout << "\n";
    cout << "  ╔══════════════════════════════════════╗\n";
    cout << "  ║         SECUREPASS ANALYZER          ║\n";
    cout << "  ║    Password Strength & Generator     ║\n";
    cout << "  ╚══════════════════════════════════════╝\n";
    cout << "\n";
}

void showMenu() {
    cout << "  ┌──────────────────────────────────┐\n";
    cout << "  │           MAIN MENU              │\n";
    cout << "  │                                  │\n";
    cout << "  │  [1]  Check Password Strength    │\n";
    cout << "  │  [2]  Generate Random Password   │\n";
    cout << "  │  [3]  About Project              │\n";
    cout << "  │  [4]  Exit                       │\n";
    cout << "  │                                  │\n";
    cout << "  └──────────────────────────────────┘\n";
    cout << "  >> Enter your choice: ";
}

void checkPasswordStrength() {
    cout << "\n  ── PASSWORD STRENGTH CHECKER ──\n\n";
    cout << "  Enter password to analyze: ";

    string password;
    cin >> password;

    int score = 0;
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;
    bool isLongEnough = false;

    for (int i = 0; i < password.length(); i++) {
        char c = password[i];

        if (c >= 'A' && c <= 'Z') hasUpper = true;
        if (c >= 'a' && c <= 'z') hasLower = true;
        if (c >= '0' && c <= '9') hasDigit = true;

        string specials = "!@#$%^&*()_+-=[]{}|;:,./?";
        for (int j = 0; j < specials.length(); j++) {
            if (c == specials[j]) {
                hasSpecial = true;
            }
        }
    }

    if (password.length() >= 8) isLongEnough = true;

    if (isLongEnough) score++;
    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    cout << "\n  ── ANALYSIS REPORT ──\n\n";
    cout << "  Password : " << password << "\n";
    cout << "  Length   : " << password.length() << " characters\n\n";

    if (isLongEnough)
        cout << "  [YES] Length >= 8 characters\n";
    else
        cout << "  [NO]  Length >= 8 characters\n";

    if (hasUpper)
        cout << "  [YES] Uppercase letters (A-Z)\n";
    else
        cout << "  [NO]  Uppercase letters (A-Z)\n";

    if (hasLower)
        cout << "  [YES] Lowercase letters (a-z)\n";
    else
        cout << "  [NO]  Lowercase letters (a-z)\n";

    if (hasDigit)
        cout << "  [YES] Numbers (0-9)\n";
    else
        cout << "  [NO]  Numbers (0-9)\n";

    if (hasSpecial)
        cout << "  [YES] Special characters (!@#...)\n";
    else
        cout << "  [NO]  Special characters (!@#...)\n";

    cout << "\n  Score    : " << score << " / 5\n";
    cout << "  Strength : ";

    if (score <= 2) {
        cout << "[ WEAK ]\n";
    } else if (score <= 3) {
        cout << "[ MEDIUM ]\n";
    } else {
        cout << "[ STRONG ]\n";
    }

    if (score < 5) {
        cout << "\n  ── SUGGESTIONS ──\n";
        if (!isLongEnough) cout << "  -> Make your password at least 8 characters long.\n";
        if (!hasUpper)     cout << "  -> Add uppercase letters (e.g. A, B, C).\n";
        if (!hasLower)     cout << "  -> Add lowercase letters (e.g. a, b, c).\n";
        if (!hasDigit)     cout << "  -> Include numbers (e.g. 1, 2, 3).\n";
        if (!hasSpecial)   cout << "  -> Use special characters (e.g. @, #, !).\n";
    } else {
        cout << "\n  Great job! Your password is strong.\n";
    }

    cout << "\n";
}

void generatePassword() {
    cout << "\n  ── PASSWORD GENERATOR ──\n\n";
    cout << "  Enter desired password length (min 8): ";

    int length;
    cin >> length;

    if (length < 8) {
        cout << "  [!] Too short. Setting length to 8.\n";
        length = 8;
    }

    string upper   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower   = "abcdefghijklmnopqrstuvwxyz";
    string digits  = "0123456789";
    string special = "!@#$%^&*";
    string allChars = upper + lower + digits + special;

    srand(time(0));

    string password = "";

    password += upper[rand() % upper.length()];
    password += lower[rand() % lower.length()];
    password += digits[rand() % digits.length()];
    password += special[rand() % special.length()];

    for (int i = 4; i < length; i++) {
        password += allChars[rand() % allChars.length()];
    }

    for (int i = password.length() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    cout << "\n  Generated Password : " << password << "\n";
    cout << "  Length             : " << length << " characters\n";
    cout << "  Strength           : [ STRONG ]\n";
    cout << "\n  Tip: Save this password somewhere safe!\n\n";
}

void showAbout() {
    cout << "\n  ── ABOUT THIS PROJECT ──\n\n";
    cout << "  Project  : SecurePass Analyzer\n";
    cout << "  Language : C++\n";
    cout << "  Made as a beginner C++ cyber security mini project.\n\n";
    cout << "  Features:\n";
    cout << "   - Checks password strength on 5 criteria\n";
    cout << "   - Gives a score out of 5\n";
    cout << "   - Suggests improvements for weak passwords\n";
    cout << "   - Generates random strong passwords\n\n";
    cout << "  Concepts used:\n";
    cout << "   - Functions, loops, if-else, switch\n";
    cout << "   - Strings and character checking\n";
    cout << "   - rand() and srand() for random numbers\n\n";
}

int main() {
    showHeader();

    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            checkPasswordStrength();
        } else if (choice == 2) {
            generatePassword();
        } else if (choice == 3) {
            showAbout();
        } else if (choice == 4) {
            cout << "\n  Thanks for using the project!\n";
            cout << "  Exiting SecurePass Analyzer. Stay secure!\n\n";
            break;
        } else {
            cout << "\n  [!] Invalid choice. Please enter 1 to 4.\n\n";
        }
    }

    return 0;
}
