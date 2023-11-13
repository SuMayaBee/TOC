#include <bits/stdc++.h>

using namespace std;

vector<vector<string>>base={{"aS"},{"aSbS"},{""}};
vector<vector<string>>sol;
bool match=false;

void cfg1(string input,string temp,vector<string> ans)
{
    if(temp.size()>input.size()+3)return;
    if(match)return;
    //if(sol.size()>=2)return;
    if(temp==input){
        match=true;
        ans.push_back(temp);
        sol.push_back(ans);
        return;
    }
    if(temp==""){
        for(int i=0;i<base.size();i++){
            if(match){
                match=false;
                if(sol.size()>=2)break;
            }
            for(int j=0;j<base[i].size();j++){
                temp=base[i][j];
                if(temp=="")ans.push_back(temp);
                cfg1(input,temp,ans);
            }
        }
    }
    else {
        int x;
        for(int x=0;x<temp.size();x++)if(temp[x]=='S')break;
        if(x==temp.size())return;
        ans.push_back(temp);
        for(int i=temp.size()-1;i>=0;i--){
            if(temp[i]=='S'){
                for(int j=0;j<base.size();j++){
                    for(int k=0;k<base[j].size();k++){
                        string u=temp;
                        u.erase(i,1);
                        u.insert(i,base[j][k]);
                        cfg1(input,u,ans);
                        if(match)return;
                    }

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
    if(sol.size()>0){
        //cout<<"YES "<<endl;
        for(int i=0;i<sol.size();i++){
            cout<<"Leftmost: ";
            for(int j=0;j<sol[i].size();j++){
                if(sol[i][j]!="")cout<<sol[i][j]<<" ";
                else cout<<"e"<<" ";
            }
            cout<<endl;
        }
    }
    else cout<<"NO"<<endl;
    if(sol.size()>=2)cout<<"It is ambiguous"<<endl;

    return 0;
}
