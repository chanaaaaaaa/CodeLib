#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<stdio.h>
#include<cmath>
#include<memory.h>
#include<iostream>
//prf do the any one or two cut between cut and cut and return the min cost
using namespace std;

int L,N,dp[55][55],cut[55];

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0'&& c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

int slove(int x,int y){
    if(~dp[x][y]){return dp[x][y];}
    if(x+1==y){return dp[x][y]=0;}
    int price=0x7fffffff;
    for(int i=x+1;i<y;i++){
        price=min(price,slove(x,i)+slove(i,y));
    }
    return dp[x][y]=price-cut[x]+cut[y];
}
signed main(){

    while(L=read()){
        if(L==0){break;}
        N=read();
        if(N==0){write(0);continue;}
        memset(cut,0,sizeof(cut));
        memset(dp,-1,sizeof(dp));
        cut[0]=0;
        for(int i=1;i<=N;i++){
            cut[i]=read();
        }
        cut[N+1]=L;
        printf("The minimum cutting is ");
        write(slove(0,N+1));
        putchar('.');
        putchar('\n');
    }
    return 0;
}
