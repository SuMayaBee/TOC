#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numOfSymbols,numOfStates,i,j,k,x;
    printf("Enter number of states: ");
    scanf("%d",&numOfStates);
    char states[numOfStates],null;
    scanf("%c",&null);
    printf("Enter set of states,Q: \n");
    for(i=0; i<numOfStates; i++)
    {
        scanf("%c",&states[i]);
        scanf("%c",&null);
    }

    printf("Enter number of symbols: ");
    scanf("%d",&numOfSymbols);
    char symbols[numOfSymbols];
    scanf("%c",&null);
    printf("Enter set of symbols: \n");
    for(i=0; i<numOfSymbols; i++)
    {
        scanf("%c",&symbols[i]);
        scanf("%c",&null);
    }
    char list[numOfStates][numOfSymbols],start,end,string[100],temp;
    for(i=0; i<numOfStates; i++)
    {
        printf("Enter transitions for %c when:\n",states[i]);
        for(j=0; j<numOfSymbols; j++)
        {
            printf("%c: ",symbols[j]);
            scanf("%c",&list[i][j]);
            scanf("%c",&null);
        }
    }

    printf("Enter start and final states: \n");
    printf("Start state: ");
    scanf("%c",&start);
    scanf("%c",&null);
    printf("Final state: ");
    scanf("%c",&end);
    scanf("%c",&null);
    temp=start;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        printf("Enter input string: ");
        scanf("%s", string);
        char path[500];
        path[0]=start;
        x=1;
        for(i=0; i<string[i]; i++)
        {
            for(j=0; j<numOfStates; j++)
            {
                if(start==states[j])break;
            }
            for(k=0; k<numOfSymbols; k++)
            {
                if(string[i]==symbols[k])
                {
                    start=list[j][k];
                    break;
                }
            }
            path[x++]='-';
            path[x++]='>';
            path[x++]=start;
        }
        path[x]=NULL;
        if(start==end)printf("Accepted\n");
        else printf("Rejected\n");
        printf("%s\n",path);
        start=temp;

    }

    return 0;
}
