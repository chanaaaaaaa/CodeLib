#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<stdio.h>
#include<algorithm>
using namespace std;
//-block

signed main(){
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++){
        int N,pos=-1,maxStart=0,maxEnd=0,num=-1,
                        Start=0,   End=0,Max=-1;
        scanf("%d",&N);
        int dat[N],maxx[N];

        for(int i=1;i<=N-1;i++){
            scanf("%d",&dat[i]);

            if(num>=0){
                num+=dat[i];
                End=i+1;
            }else{
                num=dat[i];
                Start=i;
                End=i+1;
            }

            if(num>Max || (num==Max && End-Start>maxEnd-maxStart)){
                maxStart=Start;
                maxEnd=End;
                Max=num;
            }
        }
        if(Max!=-1){
            printf("The nicest part of route %d is between stops %d and %d\n",cases,maxStart,maxEnd);
        }else{printf("Route %d has no nice parts\n",cases);}
    }
    return 0;
}
