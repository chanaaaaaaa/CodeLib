#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int i=-1,n;
string DF;

inline int di(int n){
    i++;
    if(DF[i]=='0'){return 0;}
    else if(DF[i]=='1'){return n*n;}
    else{
        return di(n/2)+di(n/2)+di(n/2)+di(n/2);
    }
}

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
    cin>>DF;
    n=read();
    write(di(n));
    return 0;
}
