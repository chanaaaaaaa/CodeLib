#include <cstdio>
#include <memory.h>
#include <cmath>

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
    return;
}
//
int N,M;
const int MAXN=1000;
int dat[MAXN][MAXN],dp[MAXN][MAXN];
signed main(){
    while(N=read()){
        M=read();
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                dat[i][j]=read();
            }
        }


        memset(dp,0,sizeof(dp));
        dp[0][0]=dat[0][0];

        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                if(i!=0){dp[i][j]=max(dp[i][j],dp[i-1][j]+dat[i][j]);}
                if(j!=0){dp[i][j]=max(dp[i][j],dp[i][j-1]+dat[i][j]);}
            }
        }
        /*
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                write(dp[i][j]);
                putchar(' ');
                putchar(' ');
            }
            putchar('\n');
        }
        */
        write(dp[N-1][M-1]);
        putchar('\n');
    }
    return 0;
}
/*
3 1 4 1 5
9 2 6 5 3
5 8 9 7 9
3 2 3 8 4
*/
/*
3  4  8  9  14
12 14 20 25 28
17 25 34 41 50
20 27 37 49
*/
