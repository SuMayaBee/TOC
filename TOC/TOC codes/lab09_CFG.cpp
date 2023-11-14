#include <iostream>
#include <map>

using namespace std;

int main()
{
    string s, m;
    cin >> s;
    int l = s.length();

    map<string, string> arr;
    arr["e"] = "p";
    arr["0"] = "p";
    arr["1"] = "p";
    arr["0p0"] = "p";
    arr["1p1"] = "p";

    if (l % 2)
    {
        m = s[l / 2];
    }
    else
    {
        m = 'e';
    }

    if (arr.find(m) == arr.end())
    {
        cerr << "Invalid input: " << endl;
        return 0;
    }
    cout << "Modified string: " << endl;
    if (l % 2) //len=odd
    {   
        s = s.substr(0, l / 2) + arr[m] + s.substr(l / 2 + 1, l);
        cout << s << endl;
    }
    else
    {
        s = s.substr(0, l / 2) + arr[m] + s.substr(l / 2, l);
        cout << s << endl;
    }

    int loop = l / 2;

    for (int i = 0; i < loop; i++)
    {
        int sL = s.length();
        
        string m = s.substr(sL / 2 - 1, 3);
        if (arr.find(m) == arr.end())
        {
            cerr << "Not in this grammar " << endl;
            return 0;
        }
        s = s.substr(0, sL / 2 - 1) + arr[m] + s.substr(sL / 2 + 2, sL);
        cout << s << endl;
    }

    return 0;
}