/*
Write a C program to prove that the following are not regular languages using pumping lemma:
a. {0n1
n
| n >= 1}
b. {0n1
2n
| n >= 1}

Your program should take the input as the following format:
i. 0^n 1^n
ii. 0^n 1^2n
Then you need to pick a string w in L and break w into three strings w = xyz such that y is not
empty and |xy| <= n. Next, you have to generate strings xykz for all k>=0 by pumping using a
function and verify whether the string is also in L using another function.
*/
#include <iostream>
#include <string>

using namespace std;

// Function to perform the pumping lemma proof

bool performPumpingLemma(string str) {
    int n = str.length();
    
        string x = str.substr(0, 1);
        string y = str.substr(1, 1);
        string z = str.substr(2);
       // string xykz;

        for(int k=0; k<10; k++) {
            // if(k==0) {
            //     string xykz = x + y + z;
            // }
            // else if( k==1) {
            //     string xykz = x + y + y + z;
            // }
            // else if (k==2) {
            //     string xykz = x + y + y + y + z;
            // }
            // else if (k==3) {
            //     string xykz = x + y + y + y + y + z;
            // }
            // else if (k==4) {
            //     string xykz = x + y + y + y + y + y + z;
            // }
           
        for(int i=0; i<k; i++) {
            y+=y;
        } 
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

            if (isInLanguage && (count0 == count1 || count0 == count1*2)) {
               // return true; // The language is regular

               continue;
            } else {
                return false;
            }
          }

        }
    

    return true; // The language is not regular
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

