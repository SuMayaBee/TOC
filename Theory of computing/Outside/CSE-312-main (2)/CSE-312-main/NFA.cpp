#include <bits/stdc++.h>

using namespace std;

char transition[100][100][100];
int numOfStates,numOfSymbols;
int check=0;
string ans;

void nfa(char startState,char finalState,string inputString,int curr,char *symbols,char *states,string path)
{
    if(startState=='X'){
        //cout<<"Rejected ";
        //cout<<path<<endl;
        return;
    }

        path+=startState;
        if(inputString[curr]==NULL && startState!=finalState)
        {
            //cout<<"Rejected ";
            //cout<<path<<endl;
            return;
        }
        if(inputString[curr]==NULL && startState==finalState)
        {
            //cout<<"Accepted ";
            //cout<<path<<endl;
            ans=path;
            check=1;
            return;
        }
        int j,k,x;
        for(j=0; j<numOfStates; j++)
        {
            if(startState==states[j])break;
        }
        for(k=0; k<numOfSymbols; k++)
        {
            if(inputString[curr]==symbols[k])break;
        }
        for(x=0; transition[j][k][x]; x++)
        {
            nfa(transition[j][k][x],finalState,inputString,curr+1,symbols,states,path);
        }

}

int main()
{
    freopen("nfa.txt","r",stdin);
    int numOfTransitions,i,j,k;
    char startState,finalState;
    string inputString;
    cin>>numOfStates>>numOfSymbols;

    char states[numOfStates],symbols[numOfSymbols];
    for(i=0; i<numOfStates; i++)cin>>states[i];
    for(i=0; i<numOfSymbols; i++)cin>>symbols[i];

    for(i=0; i<numOfStates; i++)
    {
        for(j=0; j<numOfSymbols; j++)
        {
            cin>>numOfTransitions;
            for(k=0; k<numOfTransitions; k++)
            {
                cin>>transition[i][j][k];
            }
            transition[i][j][k]=NULL;
        }
    }
    cin>>startState>>finalState;
    cin>>inputString;
    nfa(startState,finalState,inputString,0,symbols,states,"");
    //cout<<endl;
    if(check)cout<<"Accepted"<<" "<<ans<<endl;
    else cout<<"Rejected"<<endl;

    return 0;
}
