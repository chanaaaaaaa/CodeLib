#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("avx")
#include <cstdio>
#include <queue>
#include <vector>
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
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//block
const int INF=1e16;

vector<vector<pair<int,int>>>dat;
vector<int>dist;
int N,M,u,v,w;
signed main(){
    while(N=read()){
        M=read();
        dat.assign(N+1,vector<pair<int,int>>());
        dist.assign(N+1,INF);

        for(int i=0;i<M;++i){
            u=read();v=read();w=read();
            dat[u].push_back({v,w});
            //dat[v].push_back({u,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>PQ;
        dist[1]=0;
        PQ.push({0,1});
        while(!PQ.empty()){
            int cur_p=PQ.top().second;
            int cur_w=PQ.top().first;
            PQ.pop();

            if(dist[cur_p]!=cur_w){continue;}

            for(auto &[nxt,nxw]:dat[cur_p]){
                if(dist[nxt]>cur_w+nxw){
                    dist[nxt]=cur_w+nxw;
                    PQ.push({cur_w+nxw,nxt});
                }
            }
        }

        for(int i=1;i<=N;++i){
            write(dist[i]);
            putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
