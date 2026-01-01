#include <iostream>
#include <vector>
using namespace std;

const int MAXN=100001;
int n,m,time,res;

vector<int>flag(MAXN,false);
vector<int>dfn(MAXN,0);
vector<int>low(MAXN,0);
vector<vector<int>>edge(MAXN,vector<int>());

inline void tarjan(int u,int fa){

    low[u]=dfn[u]=++time;
    int child=0;
    for(const auto &v:edge[u]){
        if(!dfn[v]){
            ++child;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(fa!=u && low[v]>=dfn[u] && !flag[u]){
                flag[u]=true;
                ++res;
            }
        }else if(v!=fa){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(fa==u && child>=2 && !flag[u]){
        flag[u]=true;
        ++res;
    }
}

signed main(){
    while(cin>>n>>m){
        for(int i=0;i<m;++i){
            int x,y;
            cin>>x>>y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        for(int i=1;i<=n;++i){
            if(!dfn[i]){
                time=0;
                tarjan(i,i);
            }
        }
        cout<<res<<'\n';
        for(int i=1;i<=n;++i){
            if(flag[i]){
                cout<<i<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}