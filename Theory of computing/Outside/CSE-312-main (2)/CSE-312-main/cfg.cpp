#include <bits/stdc++.h>

using namespace std;

vector<string>base= {"e","0","1","0P0","1P1"};
vector<string>sol;
bool check=true;

void CFG(string input,string ans,string P)
{
    if(ans==input)return;
    int i,j,k,x,check1=0;
    string temp;
    if(P.size()==0)
    {
        j=input.size();
        temp.push_back(input[0]);
        if(input.size()>1)temp.push_back('P');
        while(j>0)
        {
            //cout<<j<<endl;
            for(i=1; i<j; i++)
            {
                P.push_back(input[i]);
            }
            for(k=j; k<input.size(); k++)
            {
                temp.push_back(input[k]);
            }
            for(x=0; x<base.size(); x++)
            {
                if(temp==base[x])break;
            }
            if(x==base.size())
            {
                if(temp.size()==2 && P.size()==1 && P[0]==temp[0])x--;
            }
            //cout<<temp<<" "<<P<<endl;
            if(x<base.size())
            {
                check1=1;
                break;
            }
            j--;

            temp.clear();
            P.clear();
            temp.push_back(input[0]);
            temp.push_back('P');

        }
        if(!check1)check=false;
        else
        {
            ans=temp;
            sol.push_back(ans);
            CFG(input,ans,P);
        }


    }

    else
    {
        temp.push_back(P[0]);
        if(P.size()>1)temp.push_back('P');
        string tempP;
        j=P.size();
        while(j>0)
        {
            for(i=1; i<j; i++)
            {
                tempP.push_back(P[i]);

            }
            for(k=j; k<P.size(); k++)
            {
                temp.push_back(P[k]);
            }
            //cout<<temp<<" "<<tempP<<endl;
            for(x=0; x<base.size(); x++)
            {
                if(temp==base[x])break;
            }
            if(x==base.size()){
                if(temp.size()==2 && tempP.size()==1 && tempP[0]==temp[0])x--;
            }

            if(x<base.size())
            {
                check1=1;
                break;
            }
            else
            {
                j--;
                temp.clear();
                tempP.clear();
                temp.push_back(P[0]);
                temp.push_back('P');
            }
        }
        if(!check1)check=false;
        else
        {
            for(i=0; i<ans.size(); i++)
            {
                if(ans[i]=='P'){
                    ans.erase(i,1);
                    break;
                }
            }
            ans.insert(i,temp);
            //cout<<ans<<endl;
            sol.push_back(ans);
            CFG(input,ans,tempP);
        }

    }

}


int main()
{
    string input,ans="";
    cin>>input;
    sol.push_back("P");
    CFG(input,ans,"");
    if(check)
    {
        for(int i=0; i<sol.size(); i++)
        {
            cout<<sol[i]<<endl;
        }
    }
    else cout<<"Not in this grammar";


    return 0;
}
