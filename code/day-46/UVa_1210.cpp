#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<climits>
#include<vector>

#define MAXN 10000
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
//-block
vector<int>primes;
bool isprime[MAXN+1];
int dp[MAXN+1][MAXN+1];
inline void form(){
    for(int i=2;i<MAXN;++i){
        if(!isprime[i]){primes.emplace_back(i);}
        for(auto &p:primes){
            if(i*p>MAXN){break;}
            isprime[i*p]=true;
            if(i%p==0){break;}
        }
    }
}

signed main(){
    form();
    int N;
    while(N=read()){
        int l=-1,sum=0,res=0;
        for(int i=0;N>=primes[i];++i){
            sum+=primes[i];
            while(sum>N){
                sum-=primes[++l];
            }
            if(sum==N){++res;}
        }
        write(res);
        putchar('\n');
    }
    return 0;
}
