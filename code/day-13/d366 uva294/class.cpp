#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>

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
}/*
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}*/
// -block
bool isprime[MAXP+1];
int primes[3401],pt=-1;
inline void form(){
    for(int i=2;i<=MAXP;i++){
        if(!isprime[i]){primes[++pt]=i;}
        for(int j=0;j<=pt;++j){
            if(i*primes[j]>MAXP){break;}
            isprime[i*primes[j]]=true;
            if(i%primes[j]==0){break;}
        }
    }
}

inline int slove(int x){
    int res=1,cnt;
    for(int i=0;i<=pt;++i){
        cnt=1;
        while(x%primes[i]==0){
            x/=primes[i];
            ++cnt;
        }
        if(cnt){
            res*=cnt;
        }
        if(x==1){break;}
    }
    return res;
}

signed main(void){
    form();
    //-sum primes
    int T=read(),L,U,maxx,om,tm;
    while(T--){
        L=read();U=read();maxx=0;

        for(int i=L;i<=U;++i){
            tm=slove(i);
            if(tm>maxx){maxx=tm;om=i;}
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,om,maxx);
    }
    return 0;
}
