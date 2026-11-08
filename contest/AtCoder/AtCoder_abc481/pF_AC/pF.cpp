#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

#define int long long
using namespace std;

inline int read(){
	int x=0,c=0;
	while(c<'0' || c>'9'){
		c=getchar();
		if(c==-1){return 0;}
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>=10){write(x/10);}
	putchar(x%10+'0');
	return;
}
//block

const int MOD=998244353;
const int INF=1e18;
int N,M;
vector<vector<pair<int,int>>>g;
vector<int>dist,score,rnk,best_pr,best_c;

signed main(){
	N=read();M=read();
	g.assign(N+1,{});
	for(int i=0;i<M;++i){
		int a=read(),b=read(),c=read();
		g[a].push_back({b,c});
	}

	dist.assign(N+1,-1);
	queue<int>q;
	dist[1]=0;
	q.push(1);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto [v,c]:g[u]){
			if(dist[v]==-1){
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}

	int maxd=0;
	for(int i=1;i<=N;++i){
		if(dist[i]>maxd){maxd=dist[i];}
	}
	vector<vector<int>>layer(maxd+1);
	for(int i=1;i<=N;++i){
		layer[dist[i]].push_back(i);
	}

	score.assign(N+1,0);
	rnk.assign(N+1,0);
	best_pr.assign(N+1,INF);
	best_c.assign(N+1,INF);
	score[1]=0;
	rnk[1]=0;

	for(int d=0;d<maxd;++d){
		for(int v:layer[d+1]){
			best_pr[v]=INF;
			best_c[v]=INF;
		}
		for(int u:layer[d]){
			for(auto [v,c]:g[u]){
				if(dist[v]!=d+1){continue;}
				if(rnk[u]<best_pr[v] || (rnk[u]==best_pr[v] && c<best_c[v])){
					best_pr[v]=rnk[u];
					best_c[v]=c;
					score[v]=(score[u]*10+c)%MOD;
				}
			}
		}
		vector<pair<pair<int,int>,int>>ord;
		for(int v:layer[d+1]){
			ord.push_back({{best_pr[v],best_c[v]},v});
		}
		sort(ord.begin(),ord.end());

		int cr=0;
		for(int i=0;i<(int)ord.size();++i){
			if(i && ord[i].first!=ord[i-1].first){++cr;}
			rnk[ord[i].second]=cr;
		}
	}

	for(int v=2;v<=N;++v){
		write(score[v]);
		putchar('\n');
	}
	return 0;
}
