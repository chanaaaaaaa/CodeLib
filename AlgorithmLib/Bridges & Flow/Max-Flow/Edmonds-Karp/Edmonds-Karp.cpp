#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define int long long
using namespace std;

const int MAXN=100005;
const int INF=0x7fffffff;
int n;
vector<vector<int>>capacity(MAXN,vector<int>(MAXN,0));
vector<vector<int>>edge;

inline int bfs(int s,int t,vector<int> &parent){
    fill(parent.begin(),parent.end(),-1);
    parent[s]=-2;
    queue<pair<int,int>>Q;
    Q.push({s,INF});

    while(!Q.empty()){
        int cur=Q.front().first;
        int flow=Q.front().second;
        Q.pop();
        
        for(const auto &next:edge[cur]){
            if(parent[next]==-1 && capacity[cur][next]){
                parent[next]=cur;

                int new_flow=min(flow,capacity[cur][next]);
                if(next==t){
                    return new_flow;
                }
                Q.push({next,new_flow});
            }
        }
    }
}
inline int Edmonds_Karp(int s,int t){
    int flow=0;
    vector<int>aug_path(n);
    int new_flow;

    while(new_flow=bfs(s,t,aug_path)){
        flow+=new_flow;
        int cur=t;
        while(cur!=s){
            int prev=aug_path[cur];

            capacity[prev][cur]-=new_flow;
            capacity[cur][prev]+=new_flow;

            cur=prev;
        }
    }
    return flow;
}


signed main(){
    int N,K,q;//point,edge,query
    while(cin>>N>>K>>q){
        for(int i=0;i<K;++i){
            int s,e,w;
            cin>>s>>e>>w;

            edge[s].push_back(e);
            capacity[s][e]+=w;
            capacity[e][s]-=w;
        }
        
        while(q--){
            int s,e;
            cin>>s>>e;
            
            Edmonds_Karp(s,e);
            cout<<capacity[s][e]<<'\n';
        }
    }
    return 0;
}