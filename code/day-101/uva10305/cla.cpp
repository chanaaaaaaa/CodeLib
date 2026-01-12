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
#include <vector>
#include <unordered_map>
#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0'||c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
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
const int MAXN=101;
vector<int>res;
vector<vector<int>>grid;
vector<bool>vis;
vector<bool>link;

void dfs(int x){
	vis[x]=true;
	for(auto &i:grid[x]){
        if(!vis[i]){
            dfs(i);
        }
	}
	res.emplace_back(x);
}
signed main(){
	int N,M,a,b;
	while(N=read()){
        M=read();
        if(N+M==0){break;}
		grid.assign(MAXN,vector<int>());
		vis.assign(MAXN,false);
		link.assign(MAXN,false);
		res.clear();

		while(M--){
			a=read();b=read();
			grid[a].emplace_back(b);
			link[b]=true;
		}
		for(int i=1;i<=N;++i){
            if(!link[i]){
                dfs(i);
            }
		}
		for(int i=res.size()-1;i>=0;--i){
			write(res[i]);
			if(i){
                putchar(' ');
			}else{
                putchar('\n');
			}
		}
	}
	return 0;
}
