#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("avx")
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define int long long
using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//block
const int MAXN=505;
int N,M,A[MAXN][MAXN],B[MAXN][MAXN],pfxA[MAXN][MAXN],pfxB[MAXN][MAXN];
int dp[MAXN][MAXN][2];
signed main(){
    while(N=read()){
        M=read();
        memset(pfxA,0,sizeof(pfxA));
        memset(pfxB,0,sizeof(pfxB));
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=N;++i){
            for(int j=1;j<=M;++j){
                A[i][j]=read();
                pfxA[i][j]=pfxA[i][j-1]+A[i][j];
            }
        }

        for(int i=1;i<=N;++i){
            for(int j=1;j<=M;++j){
                B[i][j]=read();
            }
        }
        for(int i=1;i<=M;++i){
            for(int j=1;j<=N;++j){
                pfxB[j][i]=pfxB[j-1][i]+B[j][i];
            }
        }

        for(int i=1;i<=N;++i){
            for(int j=1;j<=M;++j){
                dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1])+pfxA[i][j];
                dp[i][j][1]=max(dp[i][j-1][0],dp[i][j-1][1])+pfxB[i][j];
            }
        }

        write(max(dp[N][M][0],dp[N][M][1]));
        putchar('\n');
    }
    return 0;
}
