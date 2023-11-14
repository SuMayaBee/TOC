#include <iostream>
#include <string>

using namespace std;

// Function to perform the pumping lemma proof
bool performPumpingLemma(string str) {
    int n = str.length();
    for (int i = 1; i <= n; i++) {
        string x = str.substr(0, i);
        string y = str.substr(i, 1);
        string z = str.substr(i + 1);
        string xykz = x + y + z;

        // Check if |xy| <= n
        if (x.length() + y.length() <= n) {
            // Check if xy^kz is in the language
            bool isInLanguage = true;
            int count0 = 0;
            int count1 = 0;
            
            for (char c : xykz) {
                if (c == '0') {
                    count0++;
                } else if (c == '1') {
                    count1++;
                } else {
                    isInLanguage = false;
                    break;
                }
            }

            if (isInLanguage && count0 == count1) {
                return true; // The language is regular
            }
        }
    }

    return false; // The language is not regular
}

int main() {
    string input;
    cout << "Enter a string in the format 0^n1^n or 0^n1^(2n): ";
    cin >> input;

    if (performPumpingLemma(input)) {
        cout << "The language is regular." << endl;
    } else {
        cout << "The language is not regular." << endl;
    }

    return 0;
}


// 0^n 1^n
// 0^n 1^2n