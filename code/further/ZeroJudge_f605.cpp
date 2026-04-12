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
    int n,d,ans=0,con=0;
    n=read();
    d=read();
    while(n--){
        int a,b,c;
        a=read();
        b=read();
        c=read();
        if(max(max(a,b),c)-min(min(a,b),c)>=d){
            ans+=(a+b+c)/3;
            con++;
        }
    }
    write(con);
    putchar(' ');
    write(ans);
    return 0;
}
