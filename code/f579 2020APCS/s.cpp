#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<stdio.h>
using namespace std;

int a,aa=0,b,bb=0,n,IN,Ans=0;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        if(c=='-') w=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main(){
    a=read();
    b=read();
    n=read();
    while(n--){
        while(IN=read()){
            if(IN==a){aa++;}
            else if(IN==-a){aa--;}
            else if(IN==b){bb++;}
            else if(IN==-b){bb--;}
        }
        if(aa&&bb){Ans++;}
        aa=0;
        bb=0;
    }
    write(Ans);
    return 0;
}
