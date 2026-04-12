#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>


#define s second
#define f first
#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main(void){
    int N,P,time,pin,K;
    while(N=read()){
        P=read();
        vector<pair<int,pair<int,int>>>dat;//pos,gt,rt
        dat.assign(N,pair<int,pair<int,int>>());

        for(int i=0;i<N;++i){dat[i].f=read();}
        for(int i=0;i<N;++i){dat[i].s.f=read();}
        for(int i=0;i<N;++i){dat[i].s.s=read();}
        sort(dat.begin(),dat.end());
        /*
        for(int i=0;i<N;i++){
            write(dat[i].f);
            putchar(' ');
            write(dat[i].s.f);
            putchar(' ');
            write(dat[i].s.s);
            putchar('\n');
        }
        putchar('\n');
        */
        time=0,pin=0;
        for(int i=1;i<=P;++i){
            time++;
            if(i==dat[pin].f){
                K=time%(dat[pin].s.f+dat[pin].s.s);
                if(K>=dat[pin].s.f){
                    time+=dat[pin].s.f+dat[pin].s.s-K;
                }
                ++pin;
            }/*
            write(i);
            putchar('-');
            write(time);
            putchar('\n');*/
        }
        write(time);
        putchar('\n');
    }
}
