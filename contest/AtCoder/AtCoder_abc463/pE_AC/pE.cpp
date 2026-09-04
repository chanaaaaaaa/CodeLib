#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

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
//
int N,M,Y;
int u,v,t;
vector<vector<pair<int,int>>>edges;
signed main(){
    while(N=read()){
        M=read();Y=read();
        edges.assign(N+2,vector<pair<int,int>>());
        for(int i=0;i<M;++i){
            u=read();v=read();t=read();
            edges[--u].push_back({--v,t});
            edges[v].push_back({u,t});
        }
        for(int i=0;i<N;++i){
            t=read();
            edges[i].push_back({N,t});
            edges[N+1].push_back({i,t});
        }
        edges[N].push_back({N+1,Y});

        vector<int>dist(N+2,3e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>PQ;
        PQ.push({dist[0]=0,0});
        while(!PQ.empty()){
            const int dis=PQ.top().first;
            const int now=PQ.top().second;
            PQ.pop();

            if(dist[now]<dis){continue;}
            for(const auto &[nxt,cst]:edges[now]){
                if(dist[nxt]>dis+cst){
                    dist[nxt]=dis+cst;
                    PQ.push({dist[nxt],nxt});
                }
            }
        }

        for(int i=1;i<N;++i){
            write(dist[i]);
            putchar(' ');
        }

        putchar('\n');
    }
    return 0;
}
