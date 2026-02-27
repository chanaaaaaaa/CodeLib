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
#include <memory.h>

using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
/*
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}
*/
inline int min(int a,int b){
    return a>b?b:a;
}
const int INF=0x3f3f3f3f;
int dat[25],
    res[25],
    dp[1005];

signed main(){
    int N,S,cur,bt=0;
    bool f;

    while(S=read()){
        f=true;
        N=read();
        while(N--){
            dat[0]=read();
            for(int i=1;i<=dat[0];++i){
                dat[i]=read();
            }
            memset(dp,INF,sizeof(dp));
            dp[0]=0;
            cur=0;

            for(int i=1;i<=S*dat[dat[0]]+1;++i){
                for(int j=1;j<=dat[0] && i>=dat[j];++j){
                    dp[i]=min(dp[i],dp[i-dat[j]]+1);
                }
                if(dp[i]>S){
                    cur=i-1;
                    break;
                }
            }
            if(f){
                f=false;
                bt=cur;
                memcpy(res,dat,sizeof(dat));
            }else if(cur>bt){
                bt=cur;
                memcpy(res,dat,sizeof(dat));
            }else if(cur==bt){
                if(dat[0]<res[0] || dat[dat[0]]<res[res[0]]){
                    memcpy(res,dat,sizeof(dat));
                }
            }
        }
        printf("max coverage =%4d :",bt);
        for(int i=1;i<=res[0];++i){
            printf("%3d",res[i]);
        }
        putchar('\n');
    }
    return 0;
}
