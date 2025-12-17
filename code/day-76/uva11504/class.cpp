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
#pragma GCC optimize("-fdelete-null-pointer-checks")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
//#include<iostream>
#include<cstdio>
#include<vector>
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
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
vector<bool>vis;
vector<vector<int>>edge,redge;
vector<int>order,bin;
vector<bool>has_incoming;
int n,m,nscc;

inline void dfs(int u){
    vis[u]=true;
    for(int &v:edge[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    order.push_back(u);
}
inline void rdfs(int u){
    vis[u]=true;
    bin[u]=nscc;
    for(int &v:redge[u]){
        if(!vis[v]){
            rdfs(v);
        }
    }
}
inline void kos(){
    vis.clear();vis.assign(n+1,false);
    order.clear();
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(order.begin(),order.end());
    vis.clear();vis.assign(n+1,false);
    nscc=0;
    for(int &i:order){
        if(i>=1 && i<=n && !vis[i]){
            rdfs(i);
            ++nscc;
        }
    }
    
    // Calculate in-degrees of SCCs
    has_incoming.assign(nscc,false);
    for(int i=1;i<=n;++i){
        for(int &v:edge[i]){
            if(bin[i]!=bin[v]){
                has_incoming[bin[v]]=true;
            }
        }
    }
    
    int zero_in_degree_count=0;
    for(int i=0;i<nscc;++i){
        if(!has_incoming[i]){
            ++zero_in_degree_count;
        }
    }
    nscc=zero_in_degree_count;
}
signed main(){
    int N=read();
    while(N--){
        n=read(),m=read();
        edge.clear();
        redge.clear();
        order.clear();
        bin.clear();
        has_incoming.clear();

        edge.assign(n+1,vector<int>());
        redge.assign(n+1,vector<int>());
        bin.assign(n+1,0);
        nscc=0;

        while(m--){
            int x=read(),y=read();
            edge[x].push_back(y);
            redge[y].push_back(x);
        }

        kos();
        write(nscc);
        putchar('\n');
    }
}
/*

*/
