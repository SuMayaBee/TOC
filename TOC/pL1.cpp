#include <iostream>
#include <string>

using namespace std;

// Function to check if a string is in the language L = {0^n 1^n | n >= 1}
bool isInLanguageA(string str) {
    int count0 = 0;
    int count1 = 0;

    for (char c : str) {
        if (c == '0') {
            count0++;
        } else if (c == '1') {
            count1++;
        } else {
            return false;
        }
    }

    return count0 == count1 && count0 >= 1;
}

// Function to check if a string is in the language L = {0^n 1^(2n) | n >= 1}
bool isInLanguageB(string str) {
    int count0 = 0;
    int count1 = 0;

    for (char c : str) {
        if (c == '0') {
            count0++;
        } else if (c == '1') {
            count1++;
        } else {
            return false;
        }
    }

    return count0 * 2 == count1 && count0 >= 1;
}

// Function to perform the pumping lemma proof
bool performPumpingLemma(string str, bool (*isInLanguage)(string)) {
    int n = str.length();
    for (int i = 1; i <= n; i++) {
        string x = str.substr(0, i);
        string y = str.substr(i, 1);
        string z = str.substr(i + 1);
        string xykz = x + y + z;

        // Check if |xy| <= n and xy^kz is not in L
        if (x.length() + y.length() <= n && !isInLanguage(xykz)) {
            return false;
        }
    }

    return true;
}

int main() {
    string input;
    cout << "Enter a string in the format 0^n 1^n or 0^n 1^(2n): ";
    cin >> input;

    if (performPumpingLemma(input, isInLanguageA)) {
        cout << "The language is regular (L = {0^n 1^n | n >= 1})." << endl;
    } else if (performPumpingLemma(input, isInLanguageB)) {
        cout << "The language is regular (L = {0^n 1^(2n) | n >= 1})." << endl;
    } else {
        cout << "The language is not regular." << endl;
    }

    return 0;
}