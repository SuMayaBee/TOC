#include <bits/stdc++.h>
using namespace std;

int found = 0,found2=0;
string path;
vector<string>paths,paths2;

void cfg(vector<string> &base, string output, string target, string currpath)
{
    if (found>=2)
        return;

    if (output.size()>target.size()+2)
        return;

    if (output.find('S')==string::npos && output!=" ")
    {
        if (output==target)
        {
            found++;
            path = currpath;
            paths.push_back(path);
        }
        return;
    }

    for (string x : base)
    {
        if (output.find('S')!=string::npos)
        {
            string temp = output.substr(0, output.find('S'));
            temp += x;
            temp += output.substr(output.find('S') + 1);
            x = temp;
        }
        cfg(base, x, target, currpath+"->"+x);
        if (found>=2)
            return;
    }
}


int main()
{
    vector<string> base = {"aS", "aSbS", ""};
    string s;
    cin >> s;
    cfg(base, " ", s, path);

    if(found==2)
    {
        for(string x : paths)
        cout<<"Letfmost : S"+x<<endl;
        cout<<"The grammar is ambiguous"<<endl;
    }
    else
    cout<<"May not be ambiguous"<<endl;

    return 0;
}

// aab