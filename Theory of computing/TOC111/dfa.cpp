#include <stdio.h>
#define mx 100

int main()
{
    //freopen("test.txt", "r", stdin);
    char states[mx], alpha[mx], str[mx], start, end, state, path[mx], paths=0,p=0;
    int numState, numAlpha, i, j,k=0;

    printf("Enter number of states: ");
    scanf("%d", &numState);

    printf("Enter states: ");
    for (i = 0; i < numState; i++)
        scanf(" %c", &states[i]);

    printf("Enter number of Alphabet: ");
    scanf("%d", &numAlpha);
    printf("Enter alphabets: ");

    for (i = 0; i < numAlpha; i++)
        scanf(" %c", &alpha[i]);

    char transit[numState][numAlpha];
    printf("Provide transition functions: \n");
    for (i = 0; i < numState; i++)
    {
        printf("Enter transition for state %c: \n", states[i]);
        for (j = 0; j < numAlpha; j++)
        {
            printf("Enter for alphabet %c: ", alpha[j]);
            scanf(" %c", &transit[i][j]);
        }
    }

    printf("Enter starting state: ");
    scanf(" %c", &start);

    printf("Enter ending state: ");
    scanf(" %c", &end);

    printf("Enter the string: ");
    path[0]=start;
    for(k=0; k<5; k++)
    {
        scanf("%s", str);
        paths=1;
        state = start;
        for (i = 0; str[i]; i++)
        {
            for (j = 0; j<numAlpha; j++)
            {
                if (str[i]==alpha[j])
                {
                    state = transit[state-start][j];
                    break;
                }
            }
            path[paths++]=state;
        }

        if (state == end)
        {
            printf("Accepted\n");
            for(p=0; p<paths; p++)
                printf("%c ", path[p]);
        }
        else
            printf("Not accepted\n");
    }

    return 0;
}