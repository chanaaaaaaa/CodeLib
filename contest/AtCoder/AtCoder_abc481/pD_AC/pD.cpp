#include <cstdio>
#include <vector>
#include <deque>

#define int long long
using namespace std;

inline int read(){
	int x=0,c=0;
	while(c<'0' || c>'9'){
		c=getchar();
		if(c==-1){return 0;}
		if(c>='a' && c<='z'){return c-'a';}
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
}
//block
const int INF=1e18;
int N,M,S,T;
vector<vector<int>>g;
vector<int>mn,dist;

signed main(){
	N=read();M=read();S=read();T=read();
	g.assign(N+1,{});
	mn.assign(N+1,INF);
	for(int i=0;i<M;++i){
		int a=read(),b=read();
		g[a].push_back(b);
		if(b<mn[a]){mn[a]=b;}
	}
	dist.assign(N+1,INF);
	deque<int>dq;
	dist[S]=0;
	dq.push_back(S);
	while(!dq.empty()){
		int u=dq.front();dq.pop_front();
		for(int v:g[u]){
			int w=(v==mn[u]?0:1);
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				if(w==0){dq.push_front(v);}
				else{dq.push_back(v);}
			}
		}
	}
	if(dist[T]==INF){write(-1);}
	else{write(dist[T]);}
	putchar('\n');
	return 0;
}
