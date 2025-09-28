//x0 x1
//
//0=0,9=9,A=10,Z=35,a=36,z=61
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char input[100];
    while(scanf("%s",input)!=EOF){
            //printf("%s",input);
            int sum=0,t,max=1;
        for(int i=0;i<strlen(input);i++){
            if(input[i]<='9' && input[i]>='0'){
                t=(input[i]-'0');
            }
            else if(input[i]<='Z' && input[i]>='A'){
                t=(input[i]-'A'+10);
            }
            else if(input[i]<='z' && input[i]>='a'){
                t=(input[i]-'a'+36);
            }
            else continue;
            if(max<t){ max=t; }
            sum+=t;
        }
        //printf("%d %d",sum,max);
        for(int i=max;i<62;i++){
            if(!(sum%i)){
                printf("%d\n",i+1);
                break;
            }
            if(sum%i!=0 && i==61){
                printf("such number is impossible!\n");
            }
        }
    }
    return 0;
}
