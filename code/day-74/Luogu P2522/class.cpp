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
const int MAXN=10000000;
const int MOD=20101009;
int u[MAXN+5], p[MAXN/10+5],sum[MAXN+5];
bool flag[MAXN+5];
inline void init(int N,int M){
    int t=0,lim=min(N,M);
    u[1]=1;
    for(int i=2;i<=lim;++i){
        if(!flag[i]){
            p[++t]=i;
            u[i]=-1;
        }
        for(int j=1;j<=t && i*p[j]<=lim;++j){
            flag[i*p[j]]=1;
            if(i%p[j]==0){
                u[i*p[j]]=0;
                break;
            }
            u[i*p[j]]=-u[i];
        }
    }
    for(int i=1;i<=lim;++i){
        sum[i]=(sum[i-1]+i*i%MOD*(u[i]+MOD))%MOD;
    }
}
inline int SUM(int x,int y){
    return (x*(x+1)/2%MOD)*(y*(y+1)/2%MOD)%MOD;
}
inline int solve(int n,int m){
    int res=0;
    for(int l=1,r;l<=min(n,m);l=r+1){
        r=min(n/(n/l),m/(m/l));
        res=(res+(sum[r]-sum[l-1]+MOD)*SUM(n/l,m/l)%MOD)%MOD;
    }
    return res;
}

signed main(){
    int n=read(),m=read(),res=0;
    init(n,m);
    for(int l=1,r;l<=min(n,m);l=r+1){
        r=min(n/(n/l),m/(m/l));
        res=(res+(r-l+1)*(l+r)/2%MOD*solve(n/l,m/l)%MOD)%MOD;
    }
    write(res);
    putchar('\n');
	return 0;
}
