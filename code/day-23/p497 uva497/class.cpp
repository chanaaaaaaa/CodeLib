#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<algorithm>
using namespace std;

inline int read(){
    bool check=false;
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='\n' || c==-1){
            return 0;
        }
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
int T,N,cnt,maxx,data[10000],ft[10000],dp[10000];
inline void out(int d,int s){
    if(ft[s]>=s){
        putchar('M');
        putchar('a');
        putchar('x');
        putchar(' ');
        putchar('h');
        putchar('i');
        putchar('t');
        putchar('s');
        putchar(':');
        putchar(' ');
        write(d+1);
        putchar('\n');
    }else{
        out(d+1,ft[s]);
    }
    write(data[s]);
    putchar('\n');
}

signed main(){
    T=read();
    getchar();
    while(T--){
        maxx=0;cnt=-1;
        while(N=read()){
            data[++cnt]=N;
        }
        //LIS
        for(int i=0;i<=cnt;++i){
            dp[i]=1;
            ft[i]=i;
            for(int j=0;j<i;++j){
                if(data[j]<data[i] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    ft[i]=j;
                }
            }
        }
        for(int i=1;i<=cnt;i++){
            if(dp[i]>dp[maxx]){
                maxx=i;
            }
        }
        //-LIS

        if(cnt!=-1){out(0,maxx);}
        else{
            putchar('M');
            putchar('a');
            putchar('x');
            putchar(' ');
            putchar('h');
            putchar('i');
            putchar('t');
            putchar('s');
            putchar(':');
            putchar(' ');
            putchar('0');
            putchar('\n');
        }
        if(T)putchar('\n');
    }
    return 0;
}
