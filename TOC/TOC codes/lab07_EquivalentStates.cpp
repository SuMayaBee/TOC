#include <iostream>
#include <vector>
#include <set>
#include <string.h>
#include <fstream>
using namespace std;
vector<vector<string>> EquivalentSets;

int num_of_stage, num_of_input, present_state, final_state, len;
vector<char> stage(10);
vector<int> input_array(10); // Renamed to avoid conflict
int input_alpha[2];
int collectionOfEqSt[10];
int count = 0;
void printTransitionTable(vector<vector<int>> &table)
{
    cout << endl;
    for (int i = 0; i < num_of_stage; i++)
    {
        for (int j = 0; j < num_of_input; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

void minimize(vector<vector<int>> &table, vector<vector<int>> &minArray)
{
    for (int i = 0; i < num_of_stage; i++)
    {
        for (int j = 0; j < num_of_stage; j++)
        {
            if (i != j)
            {
                if ((i == final_state && j != final_state) || (i != final_state && j == final_state))
                    minArray[i][j] = 1;
                else
                    minArray[i][j] = 0;
            }
            else
                minArray[i][j] = 0;
        }
    }

    int flag = 1;
    while (flag)
    {
        flag = 0;
        for (int i = 0; i < num_of_stage; i++)
        {
            for (int j = 0; j < num_of_stage; j++)
            {
                if (i != j && !minArray[i][j])
                {
                    for (int input = 0; input < num_of_input; input++)
                    {
                        int state1 = table[i][input];
                        int state2 = table[j][input];
                        if (minArray[state1][state2] || minArray[state2][state1])
                        {
                            minArray[i][j] = 1;
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << "minimized table" << endl;
    for (int i = 0; i < num_of_stage; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << minArray[i][j] << " ";
        }
        cout << endl;
    }
}
void minimizedDFA(vector<vector<int>> &minArray, vector<vector<int>> &table, int count)
{

    for (int i = 0; i < num_of_stage; i++)
    {
        vector<string> eqSet;
        string set1, set2, state;
        for (int j = 0; j < i + 1; j++)
        {
            if (i != j && minArray[i][j] == 0)
            {

                set1 = string(1, stage[table[i][0]]) + string(1, stage[table[j][0]]);
                set2 = string(1, stage[table[i][1]]) + string(1, stage[table[j][1]]);
                state = string(1, stage[i]) + string(1, stage[j]);

                if (set1.find("d") != string::npos)

                {
                    set1 = "d";
                }
                if (set2.find("d") != string::npos)
                {
                    set2 = "d";
                }

                eqSet = {state, set1, set2};
                EquivalentSets.push_back(eqSet);
                eqSet.clear();
            }
        }
    }
    for (int i = 0; i < num_of_stage; i++)
    {
        bool found = false;
        for (int col = 0; col < count; col++)
        {
            if (i == collectionOfEqSt[col])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            string set1, set2, state;
            vector<string> eqSet;

            set1 = string(1, stage[table[i][0]]);
            set2 = string(1, stage[table[i][1]]);
            state = string(1, stage[i]);

            if (set1.find("a") != string::npos ||
                set1.find("g") != string::npos)
            {
                set1 = "ag";
            }
            if (set2.find("a") != string::npos || set2.find("g") != string::npos)
            {
                set2 = "ag";
            }
            eqSet = {state, set1, set2};
            EquivalentSets.push_back(eqSet);
            eqSet.clear();
        }
    }

    cout << "Minimized DFA transition table " << endl;
    cout << "state "
         << " 0  "
         << "1   " << endl;
    for (const vector<string> &eq : EquivalentSets)
    {
        for (string element : eq)
        {
            cout << element << "    ";
        }
        cout << endl;
    }
}
void printEquivalentStates(vector<vector<int>> &minArray)
{
    for (int i = 0; i < num_of_stage; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (i != j && minArray[i][j] == 0)
            {
                collectionOfEqSt[count++] = i;
                collectionOfEqSt[count++] = j;

                cout << "Equivalent states are: " << stage[i] << " = " << stage[j] << endl;
            }
        }
    }
}

int main()
{
    cout << "Enter stage number & number of input ";
    cin >> num_of_stage >> num_of_input;

    for (int i = 0; i < num_of_stage; i++)
    {
        cout << "Enter stages: ";
        cin >> stage[i];
    }

    for (int j = 0; j < num_of_input; j++)
    {
        cout << "Enter input alphabet ";
        cin >> input_alpha[j];
    }

    char p_state, f_state;
    cout << "Enter present & final state: ";
    cin >> p_state >> f_state;
    for (int i = 0; i < num_of_stage; i++)
    {
        if (p_state == stage[i])
        {
            present_state = i;
        }
        if (f_state == stage[i])
        {
            final_state = i;
        }
    }

    vector<vector<int>> pS(num_of_stage, vector<int>(num_of_input));
    vector<vector<int>> minArray(num_of_stage, vector<int>(num_of_stage));

    for (int i = 0; i < num_of_stage; i++)
    {
        for (int j = 0; j < num_of_input; j++)
        {
            cout << "Enter transition state for State " << stage[i] << " input " << input_alpha[j] << ": ";
            cin >> pS[i][j];
        }
    }

    cout << "transition table:" << endl;
    cout << "final st: " << final_state << endl;
    //printTransitionTable(pS);
    minimize(pS, minArray);
    printEquivalentStates(minArray);
    minimizedDFA(minArray, pS, count);

    cout << endl;

    return 0;
}
