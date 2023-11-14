#include <iostream>
#include <map>
#include <cstring>
#include <vector>
using namespace std;
bool found,foundRight;
string path,pathRight;
void leftMost(vector<string> &A, vector<string> &B, string given,
               string target, string currPath)
{

  if (found)
  {

    return;
  }
  if (given.size() > target.size() + 1)  
  {
    return;
  }

  if (given.find('A') == string::npos &&
      given.find('B') == string::npos)  //given becomes a string without A and B
  {
    if (given == target)
    {
      found = true;
      path = currPath;
    }
    return;
  }

  if (given.find('A') != string::npos)
  {
    for (string x : A)
    {
      string temp = given.substr(0, given.find('A'));
      temp += x;
      temp += given.substr(given.find('A') + 1); // append find to last 
      x = temp;                                    // updating x after appending
      leftMost(A, B, x, target, currPath + "->" + x);
     
    }
  }

  else if (given.find('B') != string::npos) //found B. same as (given.find('A')==string::nops)
  {
    for (string x : B)
    {
      string temp = given.substr(0, given.find('B'));
      temp += x;
      temp +=given.substr(given.find('B') + 1);
      x = temp;
      leftMost(A, B, x, target, currPath + "->" + x);
      
    }
  }
}

void rightMost(vector<string> &A, vector<string> &B, string given,
               string target, string currPath)
{

  if (foundRight)
  {

    return;
  }
  if (given.size() > target.size() + 1)  
  {
    return;
  }

  if (given.find('A') == string::npos &&
      given.find('B') == string::npos)  //given becomes a string without A and B
  {
    if (given == target)
    {
      foundRight = true;
      pathRight = currPath;
    }
    return;
  }

  if (given.find('B') != string::npos)
  {
    for (string x : B)
    {
      string temp = given.substr(0, given.find('B'));
      temp += x;
      temp +=given.substr(given.find('B') + 1);
      x = temp;
      rightMost(A, B, x, target, currPath + "->" + x);
     
    }
  }

  else if (given.find('A') != string::npos)
  {
    for (string x : A)
    {
      string temp = given.substr(0, given.find('A'));
      temp += x;
      temp += given.substr(given.find('A') + 1); // append find to last
      x = temp;                                    // updating x after appending
      rightMost(A, B, x, target, currPath + "->" + x);
     
    }
  }

  
}
int main()
{
  string given = "A1B"; 
  string target = "00101";
  bool flag = false;
  vector<string> A = {"", "0A"};
  vector<string> B = {"", "0B", "1B"};
  leftMost(A, B, given, target, path);
  found ? cout << "Yes" : cout << "no";
  cout << endl;
  if (found)
  {
    cout << "LeftMost Derivation: S->A1B" + path << endl;
  }

  rightMost(A, B, given, target, pathRight);
  foundRight ? cout << "Yes" : cout << "no";
  cout << endl;
  if (foundRight)
  {
    cout << "RightMost Derivation: S->A1B" + pathRight << endl;
  }
}