#include <iostream>
#include <cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
bool check=false;
bool isAlphabet(char x[], char y[], char z[],int n);
bool division(char xyz[], int n);
bool generate(int n){
    int option;
    bool ck;
    cout<<"format? 1. (0^n 1^n)  2. (0^n 1^2n) ";
    cin>>option;

    if(option==1){

    char str[2 * n + 1]; 

    for (int i = 0; i < n; i++) {
        str[i] = '0'; 
    }

    for (int i = n; i < 2 * n; i++) {
        str[i] = '1'; 
    }

    str[2 * n] = '\0';
    cout << "Generated string: " << str << endl;
    ck=division(str,strlen(str));}

    if(option==2){
     int totalLength = n + 2 * n;

    char* generatedString = new char[totalLength + 1];

   
    for (int i = 0; i < n; i++) {
        generatedString[i] = '0';
    }

   
    for (int i = n; i < totalLength; i++) {
        generatedString[i] = '1';
    }

    generatedString[totalLength] = '\0'; 
    cout << "Generated string: " << generatedString << endl;
   

    ck=division(generatedString,totalLength);
    return ck;
    
    }

    
   

}
bool division(char xyz[], int n) {
     srand(time(nullptr));

    int rand1 = rand() % (n - 2) + 1; // rand1 should be between 1 and n - 1
    int maxRand2 = n - rand1; // Maximum value for rand2
    int rand2 = (maxRand2 > 1) ? (rand() % maxRand2 + 1) : 1; // Ensure rand2 is at least 1
    
    int j;

   

    char* x = new char[rand1 + 1];
    char* y = new char[rand2 + 1];
    char* z = new char[n - rand1 - rand2 + 1];

    for (int i = 0; i < rand1; i++) {
        x[i] = xyz[i];
    }
    x[rand1] = '\0';

    cout << "x = " << x << endl;

    for (int i = rand1, j = 0; j < rand2; i++, j++) { //no need to set i's range. it will increase
        y[j] = xyz[i];
    }
    y[rand2] = '\0';

    cout << "y = " << y << endl;

    for (int i = rand1 + rand2, j = 0; i < n; i++, j++) {
        z[j] = xyz[i];
    }
    z[n - rand1 - rand2] = '\0';

    cout << "z = " << z << endl;

    bool ck=isAlphabet(x, y, z, n);

  
    delete[] x;
    delete[] y;
    delete[] z;

    return ck;
}

bool isAlphabet(char x[], char y[], char z[],int n){
   
    int flag=0;
    for(int k=0;k<5;k++){
        int len=strlen(x)+pow(strlen(y),k)+ strlen(z);
       //cout<<len<<endl;
        if(len!=n)
       
         flag=1;
         break;
    }
    if(flag==1){
      cout<<"condition xy(k)z =L breaked "<<endl;  
    }
     
      if((strlen(y)==0)|| ((strlen(x)+strlen(y))>n) || flag==1)  
      check=true;
      
      return true;
   
    
}

int main() {
    int n,counter;
    cout << "n = ";
    cin >> n;
    for(int test=0;test<3;test++){
    bool ck=generate(n);
    if(ck) counter=1;
    }
    cout<<"Result: \n";
     if(counter)
     cout<<"This string is not an alphabet"<<endl;
     else cout<<"This string is an alphabet"<<endl;

    return 0;
}
