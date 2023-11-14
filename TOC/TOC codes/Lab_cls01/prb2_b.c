#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char str[]={"1234321"};
    int len=strlen(str)-1;
    int count=0;
    printf("%c %c %d",str[1],str[len-1],len);

    for(int i=0;i<len/2;i++){
            if(str[i]==str[len-i] )
            count++;

    }

   
    printf("\ncount %d",count);
    if(count==len/2)  printf("\npallindrome");
    else printf("\nnot pallindrome");
    return 0;
}
