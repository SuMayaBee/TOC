#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream file("test_code.c");
    if(!file.is_open()){
        cout<<"Error in file opening";
        return 0;
    }
    int numOfLine=0,check=0,lineCheck=0,j,i,wordCheck=0,index=0,doneCheck=0;
    string ch,temp[100];
    while(!file.eof()){
        numOfLine++;
        getline(file,ch);
        if(doneCheck)doneCheck=0;
        for(i=0;i<ch.size();i++){
            if(i+1<ch.size() && ch[i]=='/' && ch[i+1]=='/'){
                cout<<"Line "<<numOfLine<<": ";
                for(j=i+2;j<ch.size();j++){
                    if(wordCheck==0 && ch[j]!=' '){
                        wordCheck=1;
                        cout<<ch[j];
                    }
                    else if(wordCheck==1)cout<<ch[j];
                }
                wordCheck=0;
                cout<<endl;
                break;
            }
            else if(i+1<ch.size() && ch[i]=='/' && ch[i+1]=='*'){
                lineCheck=numOfLine;
                check=1;
                temp[index]="";
                for(j=i+2;j<ch.size();j++){
                    if(j+1<ch.size() && ch[j]=='*' && ch[j+1]=='/'){
                        cout<<"Line "<<lineCheck<<": ";
                        for(int k=0;k<=index;k++){
                            cout<<temp[k]<<endl;
                        }
                        check=0;
                        index=0;
                        doneCheck=1;
                        break;
                    }
                    if(wordCheck==0 && ch[j]!=' '){
                        wordCheck=1;
                        temp[index]+=ch[j];
                    }
                    else if(wordCheck==1)temp[index]+=ch[j];
                }
                wordCheck=0;
                if(!doneCheck)index++;
                break;
            }

            else if(check){
                temp[index]="";
                for(j=i+2;j<ch.size();j++){
                    if(j+1<ch.size() && ch[j]=='*' && ch[j+1]=='/'){
                        cout<<"Line "<<lineCheck<<": ";
                        for(int k=0;k<=index;k++){
                            cout<<temp[k]<<endl;
                        }
                        check=0;
                        index=0;
                        doneCheck=1;
                        break;
                    }
                    if(wordCheck==0 && ch[j]!=' '){
                        wordCheck=1;
                        temp[index]+=ch[j];
                    }
                    else if(wordCheck==1)temp[index]+=ch[j];
                }
                wordCheck=0;
                if(!doneCheck)index++;
                break;
            }

        }

    }
    if(check){
        cout<<"##Mistake made. There was a comment that started at "<<lineCheck<<" but wasn't ended"<<endl;
    }

    return 0;
}
