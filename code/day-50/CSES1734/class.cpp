#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inilne")
#pragma GCC optimize("-fgcse")
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
#include<cstdio>
#include<algorithm>
#include<vector>
#include<math.h>

#define MAXN 200010
#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
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
}
//-block
int N,Q,nq,l,r,ans,
    res[MAXN],
    in[MAXN],
    cnt[MAXN];
vector<pair<int,pair<int,int>>>ask;
vector<int>dat(MAXN);

/*
vector<int>res(MAXN);
vector<int>in(MAXN);

vector<int>cnt(MAXN);
*/
inline void add(int n){
    if(cnt[n]==0){++ans;}
    ++cnt[n];
}
inline void minuss(int n){
    if(cnt[n]==1){--ans;}
    --cnt[n];
}


signed main(){

    N=read();Q=read();
    nq=sqrt(Q);
    ask.assign(Q,pair<int,pair<int,int>>());
    for(int i=0;i<N;++i){
        in[i]=dat[i]=read();
    }
    sort(dat.begin(),dat.end());
    dat.erase(unique(dat.begin(),dat.end()),dat.end());
    for(int i=0;i<N;++i){
        in[i]=lower_bound(dat.begin(),dat.end(),in[i])-dat.begin();
    }
    for(int i=0;i<Q;++i){
        ask[i]={i,{read()-1,read()-1}};
    }
    sort(ask.begin(),ask.end(),
         [](pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
            if(a.second.first/nq==b.second.first/nq){
                return a.second.second<b.second.second;
            }else{
                return a.second.first<b.second.first;
            }
         }
    );

    l=0;r=0;ans=1;
    ++cnt[in[0]];
    for(auto a:ask){
        while(a.second.first<l){
            --l;
            add(in[l]);
        }
        while(a.second.second>r){
            ++r;
            add(in[r]);
        }
        while(l<a.second.first){
            minuss(in[l]);
            ++l;
        }
        while(r>a.second.second){
            minuss(in[r]);
            --r;
        }
        res[a.first]=ans;
    }
    for(int i=0;i<Q;++i){
        write(res[i]);
        putchar('\n');
    }

    return 0;
}
