#include <bits/stdc++.h>

using namespace std;

bool us=false;
void pda(stack<char>s,string input,int pos)
{
    if(pos+1==input.size())return;
    int i=pos;
    while(!s.empty()){
        if(input[i]!=s.top()){
            return;
        }
        i++;
        s.pop();
    }
    if(i==input.size()){
        us=true;
        return;
    }
    for(int j=0;j<input.size();j++){
        for(i=0;i<=pos;i++)s.push(input[i]);
        pos++;
        pda(s,input,pos);
        if(us)return;
        while(!s.empty())s.pop();
    }


}

int main()
{
    string ch;
    cin>>ch;

    stack<char>s;
    pda(s,ch,0);
    if(us)cout<<"Accepted";
    else cout<<"Rejected";
    /*bool check=false,lan=true;
    for(int i=0;i<ch.size();i++){
        if(ch[i]=='0'){
            if(check){
                lan=false;
                break;
            }
            s.push(ch[i]);
        }
        else {
            check=true;
            if(!s.empty())s.pop();
            else {
                lan=false;
                break;
            }
        }
    }
    if(!lan || !s.empty())cout<<"Rejected";
    else cout<<"Accepted";*/


    return 0;
}
