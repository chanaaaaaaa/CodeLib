#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
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
#include <cstdio>
#include <set>
#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0'||c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
const int MAXN=100000000;
bool isprime[MAXN+5];
set<int>primes;
inline void form(){
    for(int i=2;i<=MAXN;++i){
        if(!isprime[i]){primes.emplace(i);}
        for(auto it=primes.cbegin();it!=primes.cend();++it){
            if(i**it>MAXN){break;}
            isprime[i**it]=true;
            if(i%*it==0){break;}
        }
    }
}
signed main(){
    form();
    int N;
    while(N=read()){
        int a=0,b=0;
        if(N&1){
            if(primes.count(N-2)){
                a=2;
                b=N-2;
            }
        }else{
            for(int i=N/2-1;i>=0;--i){
                if(primes.count(i) && primes.count(N-i)){
                    a=i;
                    b=N-i;
                    break;
                }
            }
        }

        if(a==0 && b==0){
            write(N);
            putchar(' ');putchar('i');putchar('s');putchar(' ');putchar('n');putchar('o');putchar('t');putchar(' ');putchar('t');putchar('h');putchar('e');putchar(' ');putchar('s');putchar('u');putchar('m');putchar(' ');putchar('o');putchar('f');putchar(' ');putchar('t');putchar('w');putchar('o');putchar(' ');putchar('p');putchar('r');putchar('i');putchar('m');putchar('e');putchar('s');putchar('!');
        }else{
            write(N);
            putchar(' ');putchar('i');putchar('s');putchar(' ');putchar('t');putchar('h');putchar('e');putchar(' ');putchar('s');putchar('u');putchar('m');putchar(' ');putchar('o');putchar('f');putchar(' ');
            write(a);
            putchar(' ');putchar('a');putchar('n');putchar('d');putchar(' ');
            write(b);
            putchar('.');
        }
        putchar('\n');
    }
	return 0;
}
