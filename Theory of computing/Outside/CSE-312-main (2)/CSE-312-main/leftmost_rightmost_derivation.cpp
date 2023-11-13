#include <bits/stdc++.h>

using namespace std;

vector<vector<string>>base={{"A1B"},{"0A",""},{"0B","1B",""}};
vector<string>sol;
bool match=false;

void cfg1(string input,string temp,vector<string> ans)
{
    if(temp.size()>input.size()+1)return;
    if(match)return;
    if(temp==input){
        match=true;
        for(int x=0;x<ans.size();x++){
            sol.push_back(ans[x]);
        }
        sol.push_back(temp);
        return;
    }
    ans.push_back(temp);
    if(temp==""){
        for(int i=0;i<base.size();i++){
            if(match)break;
            for(int j=0;j<base[i].size();j++){
                temp=base[i][j];
                cfg1(input,temp,ans);
            }
        }
    }
    else {
        for(int i=0;i<temp.size();i++){
            if(temp[i]=='A'){
                for(int j=0;j<base[1].size();j++){
                    string u=temp;
                    u.erase(i,1);
                    u.insert(i,base[1][j]);
                    cfg1(input,u,ans);
                    if(match)return;
                }
            }
            else if(temp[i]=='B'){
                for(int j=0;j<base[2].size();j++){
                    string u=temp;
                    u.erase(i,1);
                    u.insert(i,base[2][j]);
                    cfg1(input,u,ans);
                    if(match)return;
                }
            }
        }
    }

}

void cfg2(string input,string temp,vector<string> ans)
{
    if(temp.size()>input.size()+1)return;
    if(match)return;
    if(temp==input){
        match=true;
        for(int x=0;x<ans.size();x++){
            sol.push_back(ans[x]);
        }
        sol.push_back(temp);
        return;
    }
    ans.push_back(temp);
    if(temp==""){
        for(int i=0;i<base.size();i++){
            if(match)break;
            for(int j=0;j<base[i].size();j++){
                temp=base[i][j];
                cfg2(input,temp,ans);
            }
        }
    }
    else {
        for(int i=temp.size()-1;i>=0;i--){
            if(temp[i]=='A'){
                for(int j=0;j<base[1].size();j++){
                    string u=temp;
                    u.erase(i,1);
                    u.insert(i,base[1][j]);
                    cfg2(input,u,ans);
                    if(match)return;
                }
            }
            else if(temp[i]=='B'){
                for(int j=0;j<base[2].size();j++){
                    string u=temp;
                    u.erase(i,1);
                    u.insert(i,base[2][j]);
                    cfg2(input,u,ans);
                    if(match)return;
                }
            }
        }
    }

}

int main()
{
    string ch;
    vector<string>ans;
    cin>>ch;
    cfg1(ch,"",ans);
    if(match)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    cout<<"Leftmost: ";
    for(int i=0;i<sol.size();i++)cout<<sol[i]<<" ";
    cout<<endl;
    sol.clear();
    ans.clear();
    match=false;
    cfg2(ch,"",ans);
    if(match)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    cout<<"Rightmost: ";
    for(int i=0;i<sol.size();i++)cout<<sol[i]<<" ";

    return 0;
}
