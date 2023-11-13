#include <stdio.h>
#include <stdlib.h>

int findLength(char *binString){
    int length=0;
    for(int i=0;binString[i]!='\0';i++){
        length++;
    }
    return length;
}

int findTotal(int k){
    if(k==0)return 0;
    int total=1;
    for(int i=1;i<=k;i++){
        total*=2;
    }
    return total;
}

void checkPalindrome(){
    int i,j,checkPalindrome;
    char userString[50];
    printf("Enter string: ");
    scanf("%s",userString);
    i=0,j=findLength(userString)-1;
    while(i<=j){
        if(userString[i]!=userString[j]){
            printf("Not palindrome.\n");
            return;
        }
        i++;
        j--;
    }
    printf("It is a palindrome.\n");
}

void buildStringSet(){
    int i=0,j,k,l,total,x;
    printf("Enter value of k: ");
    scanf("%d",&k);
    total=findTotal(k);
    int arr[total];
    printf("The set of strings are: \n");
    for(i=0;i<total;i++){
        j=i;
        x=0;
        while(j){
            arr[x++]=j%2;
            j/=2;
        }
        while(x!=k)arr[x++]=0;
        for(l=x-1;l>=0;l--)
            printf("%d",arr[l]);
        printf("\n");
    }

}

int main()
{
    buildStringSet();
    checkPalindrome();

    return 0;
}
