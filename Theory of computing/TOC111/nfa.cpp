#include <iostream>
using namespace std;
#define mx 100

char transit[mx][mx][mx];
int maxS;
int numState, numAlpha;
string path;
bool isAccepted = false;

void nfaSim(char states[], char alpha[], char curr, char ending, string str, int idx, string currentPath)
{

    if (str[idx] == NULL)
    {
        if (curr == ending)
        {
            isAccepted = true;
            path = currentPath;
        }
        return;
    }

    int i, j, k;

    for (i = 0; i < numState; i++)
    {
        if (curr == states[i])
            break;
    }
    for (j = 0; j < numAlpha; j++)
    {
        if (str[idx] == alpha[j])
            break;
    }

    for (k = 0; transit[i][j][k]; k++)
    {
        nfaSim(states, alpha, transit[i][j][k], ending, str, idx + 1, currentPath +" "+ transit[i][j][k]);
    }
}

int main()
{
    freopen("nfa.txt", "r", stdin);
    char start, ending;
    string str;

    int i, j, k;

    printf("Enter number of states: ");
    scanf("%d", &numState);

    char states[numState];
    printf("Enter states: ");
    for (i = 0; i < numState; i++)
        scanf(" %c", &states[i]);

    printf("Enter number of alphabets: ");
    scanf("%d", &numAlpha);

    char alpha[numAlpha];

    printf("Enter alphabets: ");
    for (i = 0; i < numAlpha; i++)
        scanf(" %c", &alpha[i]);
    printf("Enter maximum number of transitions from a state: ");
    scanf("%d", &maxS);

    for (i = 0; i < numState; i++)
    {
        printf("Enter transitions for state %c:\n", states[i]);
        for (j = 0; j < numAlpha; j++)
        {
            printf("Enter transitions for alphabet %c:\n", alpha[j]);
            for (k = 0; k < maxS; k++)
            {
                scanf(" %c", &transit[i][j][k]);
            }
            transit[i][j][k] = NULL;
        }
    }

    printf("Enter start state: ");
    scanf(" %c", &start);

    printf("Enter end state: ");
    scanf(" %c", &ending);

    printf("Enter string: ");
    cin >> str;

    nfaSim(states, alpha, start, ending, str, 0, path);

    if (isAccepted)
        cout << "Accepted\nPath: " << path << endl;
    else
        cout << "Rejected\n";

    return 0;
}