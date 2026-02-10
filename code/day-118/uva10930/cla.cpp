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
#include <vector>
#include <memory.h>

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
const int MAXN = 30001;
int dp[MAXN],
    dat[30];
signed main(){
    int N,cases=0;

    while(N=read()){
        bool flag=false;
        int last=-1;
        memset(dp,0,sizeof(dp));
        dp[0]=1;

        for(int i=0;i<N;++i){
            dat[i]=read();
            if(!flag){
                if(dat[i]<=last || dp[dat[i]]){
                    flag=true;
                }else{
                    for(int j=MAXN-1;j>=dat[i];--j){
                        if(dp[j-dat[i]]){
                            dp[j]=1;
                        }
                    }
                }
                last=dat[i];
            }
        }
        putchar('C');
        putchar('a');
        putchar('s');
        putchar('e');
        putchar(' ');
        putchar('#');
        write(++cases);
        putchar(':');
        for(int i=0;i<N;++i){
            putchar(' ');
            write(dat[i]);
        }
        putchar('\n');

        putchar('T');
        putchar('h');
        putchar('i');
        putchar('s');
        putchar(' ');
        putchar('i');
        putchar('s');
        putchar(' ');
        if(flag){
            putchar('n');
            putchar('o');
            putchar('t');
            putchar(' ');
        }
        putchar('a');
        putchar('n');
        putchar(' ');
        putchar('A');
        putchar('-');
        putchar('s');
        putchar('e');
        putchar('q');
        putchar('u');
        putchar('e');
        putchar('n');
        putchar('c');
        putchar('e');
        putchar('.');
        putchar('\n');
    }
    return 0;
}
