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
#include<set>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

#define icc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
/*
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
}*/
//-block
vector<vector<int>>graph;
vector<int>dfn;
vector<int>low;
vector<int>res;
set<string>out;
map<string,int>mp;
map<int,string>demp;
int dep;

inline void dfs(int cur,int par){
    dfn[cur]=low[cur]=++dep;

    int child=0;

    for(auto &i:graph[cur]){
        if(!dfn[i]){
            dfs(i,cur);
            low[cur]=min(low[cur],low[i]);
            ++child;

            if((low[i] >= dfn[cur] && par!=-1)||(par==-1 && child>1)){
                res.push_back(cur);
            }
        }else if(i!=par){
            low[cur]=min(low[cur],dfn[i]);
        }
    }
}

signed main(){
    int point,edge,cases=0;
    while(cin>>point && point){
        graph.assign(point,vector<int>());
        dfn.assign(point,0);
        low.assign(point,0);
        out.clear();
        res.clear();
        mp.clear();
        demp.clear();
        dep=0;

        for(int i=0;i<point;++i){
            string s;
            cin>>s;
            mp[s]=i;
            demp[i]=s;
        }
        cin>>edge;
        for(int i=0;i<edge;++i){
            string s1,s2;
            cin>>s1>>s2;
            graph[mp[s1]].push_back(mp[s2]);
            graph[mp[s2]].push_back(mp[s1]);
        }

        for(int i=0;i<point;++i){
            if(!dfn[i]){
                dfs(i,-1);
            }
        }

        for(auto &n:res){
            out.insert(demp[n]);
        }
        if(cases){cout<<'\n';}
        cout<<"City map #"<<++cases<<": "<<out.size()<<" camera(s) found\n";
        for(auto s:out){
            cout<<s<<'\n';
        }
    }
	return 0;
}
/*
6
sugarloaf
maracana
copacabana
ipanema
corcovado
lapa
7
ipanema copacabana
copacabana sugarloaf
ipanema sugarloaf
maracana lapa
sugarloaf maracana
corcovado sugarloaf
lapa corcovado

5
guanabarabay
downtown
botanicgarden
colombo
sambodromo
4
guanabarabay sambodromo
downtown sambodromo
sambodromo botanicgarden
colombo sambodromo
0

*/
