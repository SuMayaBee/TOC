#include<stdio.h>
#include<stdlib.h>
#define max 10
char str1[max],str2[max],str3[max],str4[max],str5[max];
 char str6[5]; 
int main(){
 int flag =1;                        
                            //a no
for(int i=0;i<max;i++){
   if(i%2==0) str1[i]='1';
   else str1[i]='0';
}

for(int i=0;i<max;i++){
//    if(i%2==0) str2[i]='0';
//    else str2[i]='1';
  str2[i]=48+rand()%2;
}

for(int i=0;i<max;i++){
   if(i%3==0) str3[i]='1';
   else str3[i]='0';
}

for(int i=0;i<max;i++){
   if(i%3==0) str4[i]='0';
   else str4[i]='1';
}

for(int i=1;i<max-1;i++){
   str5[i]='2';
}  str5[0]='1';  str5[max-1]='1';


 
printf("string 1 is: %s\n",str1);
printf("string 2 is: %s\n",str2);
printf("string 3 is: %s\n",str3);
printf("string 4 is: %s\n",str4);
printf("string 5 is: %s\n",str5);
                         //b no
printf("\nLength:\n");

int count1=0,count2=0;
for(int i=0;str1[i]!='\0';i++){
  count1++;
}               
printf("length of string 1 is: %d\n",count1);
for(int i=0;str2[i]!='\0';i++){
  count2++;
}               
printf("length of string 2 is: %d\n",count2);


               //c no

 
  for(int i=0;i<max;i++){
    
    //printf("%c",str1[i]);
    if(str1[i]!='0' &&  str1[i]!='1')

    {flag=0;
    printf("\nflag %d ",flag);
    break;}
  }  
  if(flag)  printf("\nString is from the alphabet");
  else   printf("\nString is not from the alphabet");  
 
 for(int i=0;i<max;i++){
    
    //printf("%c",str1[i]);
 
    if(str5[i]!='0' &&  str5[i]!='1')

    {flag=0;
    printf("\nflag %d ",flag);
    break;}
  }  
  if(flag)  printf("\nString is from the alphabet");
  else   printf("\nString is not from the alphabet");  
 
              //d no
char string[count1+count2];
 for(int i=0,j=count1;i<count1,j<count1+count2;i++,j++){
   
    string [i]=str1[i];
    string[j]=str2[i];
    
 }

  printf("\nstring is: %s",string);
 
  

}