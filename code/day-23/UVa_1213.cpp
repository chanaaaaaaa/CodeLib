//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<memory.h>
#define MAXN 1120
#define MAXK 14
using namespace std;

inline int read(){
    bool check=false;
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(long long x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
int n,k;
bool isprime[MAXN+1];
vector<int>primes;
inline void form(){
    for(int i=2;i<=MAXN;i++){
        if(!isprime[i]){primes.emplace_back(i);}
        for(int &p:primes){
            if(p*i>MAXN){break;}
            isprime[p*i]=true;
            if(i%p==0){break;}
        }
    }
}

long long dp[MAXN+1][MAXK+1];
inline void solve(){
    for(int &p:primes){
        for(int i=MAXN;i>=p;--i){
            for(int j=MAXK;j>=1;j--){
                dp[i][j]+=dp[i-p][j-1];
            }
        }
    }
}

signed main(){
    form();
    dp[0][0]=1;
    solve();
    while(n=read(),k=read()){
        if(n+k==0){break;}
        write(dp[n][k]);
        putchar('\n');
    }
    return 0;
}
