#include <bits/stdc++.h>
using namespace std;
string pda(string s, stack<char> s1)
{
    int size = s.size();
    int flag = 0;
    for (int i = 0; i < size;)
    {
        if (s[i] == '0')
        {
            if (flag == 0)
            {
                s1.push(s[i]);
                i++;
            }
            else
            {
                return "No";
            }
        }

        else if (s[i] == '1')
        {
            flag = 1;
            if (i + 1 <= size && (s[i + 1] == '1' || s[i + 1] == '\0'))
            {
                if (!s1.empty())
                {
                    s1.pop();
                    i+=2;
                }
                else
                {
                    return "No";
                }
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
    cout << "Enter : ";
    cin >> s;
    stack<char> stack;

    cout << pda(s, stack);

    cout << endl;
    return 0;
}