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

using namespace std;

inline double read(){
    int x=0,w=1;
    char c=0;
    while(c<'0'||c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
const int MAXN=30;
int N,M,
    peo[MAXN],
    pos[MAXN],
    dat[MAXN][3],
    res;
inline void swap(int &a,int &b){
    int tmp=a;
    a=b;
    b=tmp;
    return;
}
inline int abs(int x){
    if(x<0){return -x;}
    return x;
}
inline void dfs(int now){
    if(now>=N){
        for(int i=0;i<M;++i){
            if(dat[i][2]>0){
                if(abs(pos[dat[i][0]]-pos[dat[i][1]]) > dat[i][2]){
                    return;
                }
            }
            if(dat[i][2]<0){
                if(abs(pos[dat[i][0]]-pos[dat[i][1]]) < -dat[i][2]){
                    return;
                }
            }
        }
        ++res;
        return;
    }
    for(int i=now;i<N;++i){
        swap(peo[now],peo[i]);
        pos[peo[now]]=now;
        pos[peo[i]]=i;

        dfs(now+1);

        swap(peo[now],peo[i]);
        pos[peo[now]]=now;
        pos[peo[i]]=i;
    }
    return;
}

signed main(){
    while(true){
        N=read();M=read();
        if(N+M==0){break;}

        for(int i=0;i<M;++i){
            dat[i][0]=read();
            dat[i][1]=read();
            dat[i][2]=read();
        }
        for(int i=0;i<N;++i){
            peo[i]=i;
            pos[i]=i;
        }

        res=0;
        dfs(0);
        write(res);
        putchar('\n');
    }
    return 0;
}

