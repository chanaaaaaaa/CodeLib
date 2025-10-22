//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<set>

#define MAXN 1299709
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return -1;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x*w;
}
inline void write(long long x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
set<int>primes;
bool isprime[MAXN];
int N;
inline void form(){
    for(int i=2;i<=MAXN;i++){
        if(!isprime[i]){primes.insert(i);}
        for(auto it=primes.cbegin();it!=primes.cend();it++){
            if(*it*i>MAXN){break;}
            isprime[*it*i]=true;
            if(i%*it==0){break;}
        }
    }
}

inline int solve(int x){
    if(primes.count(x)){return 0;}
    int left=x,right=x;
    while(left>=0 && !primes.count(left)){left--;}
    while(right<=MAXN && !primes.count(right)){right++;}
    return right-left;
}

signed main(){
    form();
    while(N=read()){
        write(solve(N));
        putchar('\n');
    }
    return 0;
}
