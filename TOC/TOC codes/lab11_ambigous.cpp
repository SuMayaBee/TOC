#include <bits/stdc++.h>
using namespace std;

int found = 0;
string path, path2;

void cfg(vector<string> &base, string output,
         string target, string currpath)
{
    if (found == 2)
        return;

    if (output.size() > target.size() + 2)
        return;

    if (output.find('S') == string::npos && output != " ")
    {
        if (output == target)
        {
            found++;
            if (found == 1)
                path = currpath;

            if (found == 2)
            {
                path2 = currpath;
            }
        }
        return;
    }

    for (string x : base)
    {
        if (output.find('S') != string::npos)
        {
            string temp = output.substr(0, output.find('S'));
            temp += x;
            temp += output.substr(output.find('S') + 1);
            x = temp;
        }
        cfg(base, x, target, currpath + "->" + x);
        if (found == 2)
            return;
    }
}

int main()
{
    vector<string> base = {"", "aS", "aSbS"};
    string s;
    cout << "s: ";
    cin >> s;
    cfg(base, "S", s, path);
    (found == 2) ? cout << "Yes, ambigous" : cout << "no";
    cout << endl;

    if (found == 2)
    {
        cout << "Path-1: "
             << "S" + path << endl;
        cout << "Path-2: "
             << "S" + path2 << endl;
    }
    return 0;
}
