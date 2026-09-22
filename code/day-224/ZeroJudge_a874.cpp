#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c>='A' && c<='Z'){return c-'A';}
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//block
const int MAXN=1e9+1;
int N,u,v,w,s,t;
vector<vector<pair<int,int>>>edges;
vector<int>dist;
signed main(){
    while(N=read()){
        edges.clear();
        dist.assign(26,MAXN);
        for(int i=0;i<N;++i){
            u=read();v=read();w=read();
            edges[u].push_back({v,w});
            edges[v].push_back({u,w});
        }
        s=read();t=read();

        priority_queue<int,vector<int>,greater<int>>PQ;
        PQ.push(s);dist[s]=0;
        while(!PQ.empty()){
            int cur=PQ.top();
            PQ.pop();

            for(auto &[nxt,wgt]:edges[cur]){

            }
        }
    }
    return 0;
}
