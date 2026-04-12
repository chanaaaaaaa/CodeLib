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
#include<cstdio>
#include<set>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return -1;}
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
vector<vector<int>>graph;
vector<int>dfn;
vector<int>low;
set<pair<int,int>>res;
int dep;

inline void dfs(int cur,int par){
    dfn[cur]=low[cur]=++dep;

    for(auto &i:graph[cur]){
        if(!dfn[i]){
            dfs(i,cur);
            low[cur]=min(low[cur],low[i]);
        }else if(i!=par){
            low[cur]=min(low[cur],dfn[i]);
        }
        if(low[i] > dfn[cur]){
            res.insert({min(cur,i),max(cur,i)});
        }
    }
}

signed main(){
    int point,edge;
    while(point=read(),edge=read()){
        if(point+edge==0){break;}
        graph.assign(point,vector<int>());
        dfn.assign(point,0);
        low.assign(point,0);
        dep=0;

        for(int i=0;i<edge;++i){
            int a=read(),b=read();
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(int i=0;i<point;++i){
            if(!dfn[i]){
                dfs(i,-1);
            }
        }

        write(res.size());
        for(auto it=res.cbegin();it!=res.cend();++it){
            putchar(' ');
            write(it->first);
            putchar(' ');
            write(it->second);
        }
        putchar('\n');
        res.clear();
    }
	return 0;
}
/*
4 3
0 3
0 1
0 2

7 8
0 1
0 2
1 3
2 3
3 4
4 5
4 6
5 6

0 0
*/
