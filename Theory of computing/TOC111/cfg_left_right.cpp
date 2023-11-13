#include <bits/stdc++.h>
using namespace std;

bool found = false,found2=false;
string path,path2;
void left_cfg(vector<string> &A, vector<string> &B, string output, string target, string currpath)
{
    if (found)
        return;

    if (output.size() > target.size()+1)
        return;

    if (output.find('A') == string::npos && output.find('B')==string::npos)
    {
        if (output == target)
        {
            found = true;
            path = currpath;
        }
        return;
    }

    if (output.find('A') != string::npos)
    {
        for (string x : A)
        {
            
                string temp = output.substr(0, output.find('A'));
                temp += x;
                temp += output.substr(output.find('A') + 1);
                x = temp;
            
            left_cfg(A, B, x, target, currpath + "->" + x);
            if (found)
                return;
        }
    }
    else if(output.find('A') == string::npos)
    {
        for(string x : B)
        {
            string temp = output.substr(0, output.find('B'));
            temp+=x;
            temp+=output.substr(output.find('B')+1);
            x=temp;
            left_cfg(A,B,x,target,currpath+"->"+x);
            if(found)
            return;
        }
    }
}

void right_cfg(vector<string> &A, vector<string> &B, string output, string target, string currpath)
{
    if (found2)
        return;

    if (output.size() > target.size()+1)
        return;

    if (output.find('A') == string::npos && output.find('B')==string::npos)
    {
        if (output == target)
        {
            found2 = true;
            path2 = currpath;
        }
        return;
    }

    if (output.find('B') != string::npos)
    {
        for (string x : B)
        {
            
                string temp = output.substr(0, output.find('B'));
                temp += x;
                temp += output.substr(output.find('B') + 1);
                x = temp;
            
            right_cfg(A, B, x, target, currpath + "->" + x);
            if (found2)
                return;
        }
    }
    else if(output.find('B') == string::npos)
    {
        for(string x : A)
        {
            string temp = output.substr(0, output.find('A'));
            temp+=x;
            temp+=output.substr(output.find('A')+1);
            x=temp;
            right_cfg(A,B,x,target,currpath+"->"+x);
            if(found2)
            return;
        }
    }
}


int main()
{
    vector<string> A = {"0A", ""}, B = {"0B", "1B", ""};
    string s;
    cin >> s;
    left_cfg(A, B, "A1B", s, path);
    found ? cout << "Yes" : cout << "no";
    cout << endl;
    if (found)
    {
        cout<<"LeftMost Derivation: S->A1B"+path<<endl;
    }
    right_cfg(A,B,"A1B", s,path2);
    if (found2)
    {
        cout<<"RightMost Derivation: S->A1B"+path2<<endl;
    }
    return 0;
}