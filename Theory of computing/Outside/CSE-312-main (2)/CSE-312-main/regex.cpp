#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    int numOfStates,numOfSymbols,i,j,k;
    cin>>numOfStates>>numOfSymbols;

    char states[numOfStates+1],symbols[numOfSymbols+1],dfa[numOfStates+1][numOfSymbols+1],startState,endState;
    for(i=1;i<=numOfStates;i++){
        cin>>states[i];
    }
    for(i=1;i<=numOfSymbols;i++){
        cin>>symbols[i];
    }
    for(i=1;i<=numOfStates;i++){
        for(j=1;j<=numOfSymbols;j++){
            cin>>dfa[i][j];
        }
    }
    cin>>startState>>endState;

    // for(i=1;i<=numOfStates;i++){
    //     for(j=1;j<=numOfSymbols;j++){
    //         cout<<dfa[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    string regex[3][numOfStates+1][numOfStates+1];

    for(i=1; i<=numOfStates; i++)
    {
        for(j=1; j<=numOfStates; j++)
        {
            for(k=1; k<=numOfSymbols; k++)
            {
                if(dfa[i][k]==states[j])
                {
                    regex[0][i][j] += symbols[k];
                    if(states[i]==states[j]){
                        regex[0][i][j]+="+E";
                    }
                    break;
                }

            }
            if(k>numOfSymbols)regex[0][i][j]+="N";
        }
    }

    for(k=1;k<3;k++){
        for(i=1;i<=numOfStates;i++){
            for(j=1;j<=numOfStates;j++){
                regex[k][i][j]=regex[k-1][i][j]+"+"+regex[k-1][i][k]+"("+regex[k-1][k][k]+")*"+regex[k-1][k][j];
            }
        }
    }
    
    for(i=0;i<3;i++){
        for(j=1;j<=numOfStates;j++){
            for(k=1;k<=numOfStates;k++){
                cout<<"R"<<"("<<i<<")"<<states[j]<<states[k]<<": "<<regex[i][j][k]<<endl;
            }
        }
    }
    

    return 0;
}