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
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}
//-block
const int N=15;
const int MAXN=105;

struct plz{
    int w,h,m;
}P[N];

int W,H,cnt,sum,
    dat[MAXN][MAXN];

inline void swap(int &a,int &b){
    int tmp=a;
    a=b;
    b=tmp;
    return;
}

inline void init(){
    memset(dat,0,sizeof(dat));
    sum=0;
    for(int i=0;i<cnt;++i){
        P[i].m=read();
        P[i].w=read();
        P[i].h=read();
        sum+=P[i].m;
    }
}
inline bool check(int w,int h,plz p,int d){
    if(d){
        if(p.h==p.w){return false;}
        swap(p.w,p.h);
    }
    if(w+p.w>W || h+p.h>H){return false;}
    for(int i=w;i<w+p.w;++i){
        for(int j=h;j<h+p.h;++j){
            if(dat[i][j]){return false;}
        }
    }
    return true;
}
inline void tring(int w,int h,plz p,int d){
    if(d){
        swap(p.w,p.h);
    }
    for(int i=w;i<w+p.w;++i){
        for(int j=h;j<h+p.h;++j){
            dat[i][j]=(dat[i][j]^1);
        }
    }
    return;
}
inline int solve(int w,int h,int c){
    int tmp=0;
    if(c==sum){return 1;}
    if(h==H){return solve(w+1,0,c);}
    if(dat[w][h]){return solve(w,h+1,c);}

    for(int i=0;i<cnt;++i){
        if(!P[i].m){continue;}
        if(check(w,h,P[i],0)){
            tring(w,h,P[i],0);
            --P[i].m;

            tmp+=solve(w,h+1,c+1);

            tring(w,h,P[i],0);
            ++P[i].m;
        }
        if(check(w,h,P[i],1)){
            tring(w,h,P[i],1);
            --P[i].m;

            tmp+=solve(w,h+1,c+1);

            tring(w,h,P[i],1);
            ++P[i].m;
        }
    }
    return tmp;
}
signed main(){
    while(W=read()){
        H=read();cnt=read();

        init();
        write(solve(0,0,0));
        putchar('\n');
    }
    return 0;
}
