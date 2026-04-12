#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

#include<stdio.h>
#include<cmath>
using namespace std;

int main(){
    int c;
    while(scanf("%d",&c)){
        if(c==0){break;}
        int cal=c*4-3,Ans=1,cou=1,zu=3;

        while(cal!=1){
            if(cal%zu==0){
                cal/=zu;
                cou++;
                printf("%d ",zu);
            }else{
                Ans*=cou;
                cou=1;
                zu+=2;
            }
        }
        printf("%d %d\n",c,Ans*2);
    }
    return 0;
}
