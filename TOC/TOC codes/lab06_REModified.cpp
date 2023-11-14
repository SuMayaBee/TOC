#include <iostream>
#include <string>
using namespace std;

string R0[3][4][4];

int main()
{
    freopen("RE.txt", "r", stdin);
    int i, j, k = 0;
    string expression;

    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 3; j++)
        {

            cin >> R0[1][i][j];
        }
    }
   for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 3; j++)
        {

            cout << "i" << i << "j" << j << " " << R0[1][i][j] << "    ";

            cout << endl;
        }
    }
    cout << "RE for k=1 and k=2" << endl;

    for (k = 1; k <= 2; k++)
    {
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {    size_t found1 = R0[k][i][j].find("-1");
            if (found1 != string::npos) {
                R0[k][i][j].replace(found1, 2, "");
            }
            size_t found2 = R0[k][i][k].find("-1");
            if (found2 != string::npos) {
                R0[k][i][k].replace(found2, 2, "");
            }
            size_t found3 = R0[k][k][k].find("-1");
            if (found3 != string::npos) {
                R0[k][k][k].replace(found3, 2, "");
            }
              
                cout << "R" << i << j << "(" << k << ")= " << R0[k][i][j] << "+" << R0[k][i][k] << "(" << R0[k][k][k] << ")*" << R0[k][k][j] << endl;
                expression = R0[k][i][j] + "+" + R0[k][i][k] + "(" + R0[k][k][k] + ")*" + R0[k][k][j];
                R0[k + 1][i][j] = expression;
            }
        }
    }
}