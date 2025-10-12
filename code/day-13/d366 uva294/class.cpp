#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<string>

#define MAXN 1000000000
#define MAXP 31623
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0'&& c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
// -block
bool isprime[MAXP+1];
vector<int>primes;
map<int,int>lib;
inline void form(){
    for(int i=2;i<=MAXP;i++){
        if(!isprime[i]){primes.emplace_back(i);}
        for(auto &p:primes){
            if(i*p>MAXP){break;}
            isprime[i*p]=true;
            if(i%p==0){break;}
        }
    }
}

inline int slove(int x){
    for(auto &p:primes){
        int cnt=0;
        while(x%p==0){
            x/=p;
            cnt++;
        }
        if(cnt){
            lib[p]=cnt;
        }
        if(x==1){break;}
    }
    x=1;
    for(auto &i:lib){
        x*=(i.second+1);
    }
    return x;
}
inline void say(string x){
    for(int i=0;i<x.size();i++){
        putchar(x[i]);
    }
}
signed main(void){
    form();/*
    for(auto &i:primes){
        write(i);
        putchar(' ');
    }*/

    //-sum primes
    int T=read(),L,U,maxx=-1,om,tm;
    while(T--){
        L=read();U=read();maxx=0;

        say("Between ");
        write(L);

        while(L<=U){
            tm=slove(L);
            if(tm>maxx){maxx=tm;om=L;}
            L++;
            lib.clear();
        }

        say(" and ");
        write(U);
        say(", ");
        write(om);
        say(" has a maximum of ");
        write(maxx);
        say(" divisors.");
        putchar('\n');
    }
    return 0;
}
