#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inilne")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-ferun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-function-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")

//#include<iostream>
#include<cstdio>
#include<vector>
#include<math.h>
#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c>'9' || c<'0'){
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
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-blcok
const int MAXN=250000;
vector<bool>isprime(MAXN+1,false);
vector<int>primes;
inline void p_form(){
    for(int i=2;i<MAXN;++i){
        if(!isprime[i]){primes.push_back(i);}
        for(int &n:primes){
            if(n*i>MAXN){break;}
            isprime[i*n]=true;
            if(i%n==0){break;}
        }
    }
    primes[0]=3;
    primes[1]=4;
}
vector<long double>fab(MAXN,1);
inline void f_form(){
    bool lim=false;
    for(int i=2;i<MAXN;++i){
        if(lim){
            fab[i]=fab[i-1]+fab[i-2]/10;
            lim=false;
        }else{
            fab[i]=fab[i-1]+fab[i-2];
        }
        if(fab[i] > 1e9){
            fab[i]/=10;
            lim=true;
        }
    }
}
signed main(){
    p_form();
    f_form();
    int N;
    while(N=read()){
        write((int)fab[primes[N-1]-1] + 1e-7);
        putchar('\n');
    }
    return 0;
}
/*

*/
