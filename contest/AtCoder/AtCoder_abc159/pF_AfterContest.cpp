#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <iostream>

#define int long long
using namespace std;

inline int read(){
    int x=0,w=1,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
const int MOD=998244353;
const int MAXN=3e3+10;
int dat[MAXN],dp[MAXN];
int N,S,res;
signed main(){
    N=read();S=read();res=0;
    for(int i=1;i<=N;++i){
        dat[i]=read();
    }

    for(int i=1;i<=N;++i){
        for(int j=S;j>=dat[i];--j){
            dp[j]=(dp[j]+dp[j-dat[i]])%MOD;
        }
        if(dat[i]<=S){
            dp[dat[i]]=(dp[dat[i]]+i)%MOD;
        }
        res=(res+dp[S])%MOD;
    }

    write(res);
    putchar('\n');
    return 0;
}
