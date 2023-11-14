#include <bits/stdc++.h>
using namespace std;

string pda(string s, stack<char> s1)
{
    int d = s.size();
    int flag = 0;

    for (int i = 0; i < d; i++)
    {
        if (s[i] == '0')
        {
            if (!flag)
            {
                s1.push(s[i]);
            }
            else
                return "No";
        }
        else if (s[i] == '1')
        {
            flag = 1;
            if (!s1.empty())
            {
                s1.pop();
            }
        }
    }

    if (s1.empty())
        return "Yes";

    return "No";
}

int main()
{

    string s;
    cin >> s;
    stack<char> stack;

    cout << pda(s, stack);

    cout << endl;
    return 0;
}