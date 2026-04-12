//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
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
int dp[15][15][15]={0},
    N,a,b,c;
inline void form(){
    dp[1][1][1]=1;
    for(int i=2;i<=13;i++){
        for(int a=1;a<=i;a++){
            for(int b=1;b<=i;b++){
                dp[i][a+1][b]+=dp[i-1][a][b];
                dp[i][a][b+1]+=dp[i-1][a][b];
                dp[i][a][b]+=dp[i-1][a][b]*(i-2);
            }
        }
    }
}

signed main(){
    form();
    N=read();
    while(N--){
        a=read(),b=read(),c=read();
        if(a<=0 || a>13 || b<=0 || b>13 || c<=0 || c>13 || b>a || c>a){
            putchar('0');
        }else{
            write(dp[a][b][c]);
        }
        putchar('\n');
    }
    return 0;
}
