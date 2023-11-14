#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num_of_stage,num_of_input,present_state,final_state,input[10],len;
  printf("Enter stage number & number of input ");
  scanf("%d %d",&num_of_stage,&num_of_input);
  char stage[num_of_stage];
 for(int i=0;i<num_of_stage;i++){
     printf("Enter stages: ");
     scanf(" %c",&stage[i]);
 }
 int input_alpha[num_of_input];
  for(int j=0;j<num_of_input;j++){
      printf("Enter input alphabet ");
      scanf("%d",&input_alpha[j]);
  }

printf("Enter input string:(-1 to stop)  ");
for(int i=0;i<10;i++){
    scanf("%d",&input[i]);
    len++;
    if(input[i]==-1) break;
}
char p_state,f_state;
printf("Enter present & final state: ");
scanf(" %c %c",&p_state,&f_state);
for(int i=0;i<num_of_stage;i++){
    if(p_state==stage[i]){present_state=i;}
    if(f_state==stage[i]){final_state=i;}
}
//printf(" pf %d %d",present_state,final_state);
int pS[num_of_stage][num_of_input];
for(int i=0;i<num_of_stage;i++){
    for(int j=0;j<num_of_input;j++){
        printf("Enter transition state for State %c input %d: ",stage[i],input_alpha[j]);
        scanf("%d",&pS[i][j]);
    }
}
for(int x=0;x<len-1;x++){
        int check=input[x];
        present_state=pS[present_state][check];
       printf("updated state %d\n  ",present_state);

}
if(present_state==final_state){printf("Accepted");}
else {printf("Rejected");}
}