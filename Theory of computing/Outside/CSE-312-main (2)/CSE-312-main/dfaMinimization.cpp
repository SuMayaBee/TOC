#include <bits/stdc++.h>

using namespace std;

int findindex(char x,char states[],int n)
{
    int pos;
    for(int i=0; i<n; i++)
    {
        if(states[i]==x)
        {
            pos=i;
            break;
        }
    }
    return pos;
}

int main()
{
    freopen("mini2.txt","r",stdin);

    int numOfStates,numOfSymbols,i,j,k;
    cin>>numOfStates>>numOfSymbols;

    char states[numOfStates],symbols[numOfSymbols],dfa[numOfStates][numOfSymbols],startState,endState;
    for(i=0; i<numOfStates; i++)cin>>states[i];
    for(i=0; i<numOfSymbols; i++)cin>>symbols[i];
    for(i=0; i<numOfStates; i++)
    {
        for(j=0; j<numOfSymbols; j++)
        {
            cin>>dfa[i][j];
        }
    }
    cin>>startState>>endState;

    char table[numOfStates][numOfStates];
    for(i=0; i<numOfStates; i++)
    {
        for(j=0; states[i]!=states[j]; j++)
        {
            table[i][j]=' ';
            if(states[j]==endState || states[i]==endState)
            {
                table[i][j]='X';
            }
        }
    }

    for(int z=0; z<2; z++)
    {
        for(i=0; i<numOfStates; i++)
        {
            for(j=0; states[i]!=states[j]; j++)
            {
                for(k=0; k<numOfSymbols; k++)
                {
                    char u=dfa[i][k],v=dfa[j][k];
                    int x=findindex(u,states,numOfStates),y=findindex(v,states,numOfStates);
                    if(table[x][y]=='X' || table[y][x]=='X')
                    {
                        table[i][j]='X';
                        break;
                    }
                }
            }
        }
    }

    for(i=1; i<numOfStates; i++)
    {
        for(j=0; states[i]!=states[j]; j++)
        {
            if(table[i][j]!='X')table[i][j]='=';
        }
    }

    cout<<"Table: "<<endl;
    for(i=1; i<numOfStates; i++)
    {
        for(j=0; states[i]!=states[j]; j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    vector< set<char> >tempStates;
    vector< vector<char> >transition;
    vector<char>newStates;
    char newStartState,newEndState;
    char statesCopy[numOfStates];
    for(i=0;i<numOfStates;i++)
    {
        statesCopy[i]=states[i];
    }

    for(i=0;i<numOfStates-1;i++)
    {
        set<char>temp;
        for(j=numOfStates-1;j>0;j--){
            if(table[j][i]=='='){
                temp.insert(states[i]);
                temp.insert(states[j]);
                statesCopy[i]=statesCopy[j]='X';
            }
        }
        if(temp.size()>0)tempStates.push_back(temp);
    }

    for(i=0;i<numOfStates;i++)
    {
        if(statesCopy[i]!='X')
        {
            set<char>temp;
            temp.insert(statesCopy[i]);
            tempStates.push_back(temp);
        }
    }

    for(i=0;i<tempStates.size();i++){
        set<char>::iterator itr=tempStates[i].begin();
        newStates.push_back(*itr);
        if(*itr==startState)newStartState=*itr;
        if(*itr==endState)newEndState=*itr;
    }

    for(i=0;i<tempStates.size();i++)
    {
        vector<char>temp1;
        set<char>::iterator x = tempStates[i].begin();
        int pos=-1;
        for(;x!=tempStates[i].end();x++){
            for(j=0;j<numOfStates;j++){
                if(states[j]==*x)pos=j;
            }
        }
        for(j=0;j<numOfSymbols;j++){
            char tempState=dfa[pos][j];
            for(k=0;k<tempStates.size();k++){
                set<char>::iterator itr=tempStates[k].find(tempState);
                if(itr!=tempStates[k].end()){
                //     temp1.push_back(newStates[k]);
                     temp1.push_back(*tempStates[k].begin());
                }
            }
        }
        transition.push_back(temp1);
    }

    cout<<"New States: ";
    for(i=0;i<transition.size();i++){
        cout<<newStates[i]<<" ";
    }
    cout<<endl;
    cout<<"Symbols: ";
    for(i=0;i<numOfSymbols;i++){
        cout<<symbols[i]<<" ";
    }
    cout<<endl;
    cout<<"Transition table: "<<endl;

    for(i=0;i<transition.size();i++){
        for(j=0;j<numOfSymbols;j++){
            cout<<transition[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Start state: "<<newStartState<<endl;
    cout<<"End state: "<<newEndState<<endl;

    return 0;
}
