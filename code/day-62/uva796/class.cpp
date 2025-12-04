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
#include<queue>
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
    if(x<0){putchar('-');return;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
inline void clLks(){
    putchar(' ');
    putchar('c');
    putchar('r');
    putchar('i');
    putchar('t');
    putchar('i');
    putchar('c');
    putchar('a');
    putchar('l');
    putchar(' ');
    putchar('l');
    putchar('i');
    putchar('n');
    putchar('k');
    putchar('s');
    putchar('\n');
    return;
}
vector<vector<int>>graph;
vector<int>dfn,low;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>result;
int dep;

void dfs(int cur, int par){
	dfn[cur]=low[cur]=++dep;

	for(auto& i:graph[cur]){

		if(!dfn[i]){
			dfs(i,cur);
			low[cur]=min(low[cur],low[i]);
		}else if(i!=par){
		    low[cur]=min(low[cur],dfn[i]);
		}

		if(low[i]>dfn[cur]){
            result.push({min(i,cur),max(i,cur)});
        }
	}
}

signed main(){
	int N;

	while(N=read()+1){
        --N;
		graph.assign(N,vector<int>());
		dfn.assign(N,0);
		low.assign(N,0);
		dep=0;

		for(int i=0,a,b,n;i<N;++i){
			a=read();
			n=read();
			while(n--){
                b=read();
                graph[a].emplace_back(b);
            }
		}

		for(int i=0;i<N;++i){
            if(!dfn[i]){
                dfs(i,-1);
            }
        }
        write(result.size());
        clLks();

		while(!result.empty()){
            write(result.top().first);
            putchar(' ');
            putchar('-');
            putchar(' ');
            write(result.top().second);
			putchar('\n');
			result.pop();
		}
		putchar('\n');
	}
	return 0;
}
/*
8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)

0
*/
