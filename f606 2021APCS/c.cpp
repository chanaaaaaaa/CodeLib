#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<iostream>
using namespace std;

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

signed main(){
    int n,m,k;
    n=read();
    m=read();
    k=read();
    int dat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dat[i][j]=read();
        }
    }
    int Ans=0x7fffffff;
    while(k--){
        int now=0,to[m][m];
        fill(to[0],to[0]+m*m,0);
        for(int i=0;i<n;i++){
            int in=read();
            for(int j=0;j<m;j++){
                to[in][j]+=dat[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j){now+=to[i][j];}
                else if(to[i][j]<=1000){now+=to[i][j]*3;}
                else{now+=3000+(to[i][j]-1000)*2;}
            }
        }
        Ans=min(Ans,now);
    }
    write(Ans);
    return 0;
}
