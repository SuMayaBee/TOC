#include <stdio.h>
#include <math.h>
#include<string.h>
int binaryNum[32]; // Assuming integers are 32 bits in size

int main() {
    int k;
    int j = 0;
    
    printf("enter k: ");
    scanf("%d", &k);
    int totalNumbers = (int)pow(2, k); // Cast the result of pow to an integer
    
    for (int i = 0; i < totalNumbers; i++) {
        int num = i;
        j = 0;
        
        while (j < k) {
            binaryNum[j] = num % 2;
            num /= 2;
            j++;
        }
        
        for (int x = k - 1; x >= 0; x--) {
            printf("%d", binaryNum[x]);
        }
        
        printf("\n");
    }
    


                    //b no

    char str[]={"1234321"};
    int len=strlen(str)-1;
    int count=0;
    //printf("%c %c %d",str[1],str[len-1],len);

    for(int i=0;i<len/2;i++){
            if(str[i]==str[len-i] )
            count++;

    }

   
    //printf("\ncount %d",count);
    if(count==len/2)  printf("\npallindrome");
    else printf("\nnot pallindrome");                
    return 0;
}
