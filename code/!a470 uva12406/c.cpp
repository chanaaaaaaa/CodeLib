#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<iostream>
#include<cmath>
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
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int t=read();
    for(int i=1;i<=t;i++){
        long maxx,q,big=-1;
        maxx=pow(10,read());
        q=pow(2,read());
        cout<<"Case "<<i<<": ";

        int dq=q,c=0;
        while(dq<maxx/10){
            dq+=q;
        }
        while(dq<maxx){
            int check=dq,flag=1;
            while(check){
                if(check%10!=1 && check%10!=2){flag=0;break;}
                check/=10;
            }
            if(flag){
                if(big==-1){
                    write(dq);
                }else{c=1;}
                big=dq;
            }
            dq+=q;
        }
        if(c==1){
            putchar(' ');
            write(big);
        }else if(big==-1){cout<<"impossible";}
        putchar('\n');
    }
    return 0;
}
