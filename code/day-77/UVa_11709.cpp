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
#include<iostream>
//#include<cstdio>
#include<vector>
#include<map>
#include<vector>
#include<stack>
#define int long long
#define icc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

//-block
vector<int>dfn;
vector<int>low;
vector<vector<int>>grid;
vector<bool>instack;

stack<int>s;
map<string,int>mp;

int res,dfstime;

inline void tarjan(int u){
    dfn[u]=low[u]=++dfstime;
    s.push(u);
    instack[u]=true;

    for(auto &v:grid[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(instack[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        int a=-1;
        do{
            a=s.top();
            s.pop();
            instack[a]=false;
        }while(a!=u);
        ++res;
    }
}
signed main(){
    int N,M;
    while(cin>>N>>M && (N || M)){
        cin.ignore();
        dfn.clear();
        low.clear();
        grid.clear();
        instack.clear();
        mp.clear();
        while(!s.empty()){s.pop();}

        dfn.assign(N+1,0);
        low.assign(N+1,0);
        instack.assign(N+1,false);
        grid.assign(N+1,vector<int>());
        res=0;dfstime=0;

        for(int i=0;i<N;++i){
            string s;
            getline(cin,s);
            mp[s]=i;
        }
        for(int i=0;i<M;++i){
            string s1,s2;
            getline(cin,s1);
            getline(cin,s2);

            grid[mp[s1]].push_back(mp[s2]);
        }

        for(int i=0;i<N;++i){
            if(!dfn[i]){
                tarjan(i);
            }
        }
        cout<<res<<'\n';
    }
}
/*
3 2
McBride , John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
Smith, Peter
Brown, Anna
3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
McBride, John
Smith, Peter
0 0
*/
