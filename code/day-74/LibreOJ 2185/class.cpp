/*
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inilne")
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
#pragma GCC optimize("-fdelete-null-pointer-checks")*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
//#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
#define icc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
const int MAXN=50000;
int pr[MAXN+5],u[MAXN+5],d[MAXN+5],t[MAXN+5],cnt;
bool bp[MAXN+5];
inline void init(int lim){
    bp[0]=bp[1]=u[1]=d[1]=1;
    for(int i=2;i<=lim;++i){
        if(!bp[i]){
            pr[++cnt]=i;
            u[i]=-1;
            d[i]=2;
            t[i]=1;
        }
        for(int j=1;j<=cnt && i*pr[j]<=lim;++j){
            bp[i*pr[j]]=1;
            if(i%pr[j]==0){
                u[i*pr[j]]=0;
                d[i*pr[j]]=d[i]/(t[i]+1)*(t[i]+2);
                t[i*pr[j]]=t[i]+1;
                break;
            }else{
                u[i*pr[j]]=-u[i];
                d[i*pr[j]]=d[i]<<1;
                t[i*pr[j]]=1;
            }
        }
    }
    for(int i=2;i<=lim;++i){
        u[i]+=u[i-1];
        d[i]+=d[i-1];
    }
}

inline int solve(int n,int m){
    int res=0;
    for(int l=1,r;l<=min(n,m);l=r+1){
        r=min(n/(n/l),m/(m/l));
        res+=d[n/l]*d[m/l]*(u[r]-u[l-1]);
    }
    return res;
}

signed main(){
    init(50000);
    int N=read();
    while(N--){
        write(solve(read(),read()));
        putchar('\n');
    }
	return 0;
}
