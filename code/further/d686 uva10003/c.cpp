//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;

int L,N,dp[55][55],cut[55];

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0'&& c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main(){

    while(L=read()){
        N=read();

        memset(cut,0,sizeof(cut));
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=N;i++){
            cut[i]=read();
        }
        cut[0]=0;
        cut[++N]=L;
        for(int i=0;i<=N;++i){
            for(int j=0;j<=N;++j){
                dp[i][j]=0x7fffffff;
            }
        }
        for(int i=0;i<N;i++){
            dp[i][i+1]=0;
        }
        for(int i=L;i>=0;i--){
            for(int j=i+1;j<=N;j++){
                for(int k=i+1;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+cut[j]-cut[i]);
                }
            }
        }
        putchar('T');
        putchar('h');
        putchar('e');
        putchar(' ');
        putchar('m');
        putchar('i');
        putchar('n');
        putchar('i');
        putchar('m');
        putchar('u');
        putchar('m');
        putchar(' ');
        putchar('c');
        putchar('u');
        putchar('t');
        putchar('t');
        putchar('i');
        putchar('n');
        putchar('g');
        putchar(' ');
        putchar('i');
        putchar('s');
        putchar(' ');
        write(dp[0][N]);
        putchar('.');
        putchar('\n');
    }
    return 0;
}
