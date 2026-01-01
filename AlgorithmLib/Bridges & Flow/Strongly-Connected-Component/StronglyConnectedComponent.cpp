#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAXN=100005;
vector<vector<int>>edges;
stack<int>stk;
vector<bool>instack(MAXN,0);
vector<int>dfn(MAXN,0);
vector<int>low(MAXN,0);
vector<vector<int>>scc;
int time,x;

inline void tarjan(int u){
    dfn[u]=low[u]=++time;
    stk.push(u);
    instack[u]=true;
    for(const auto &v:edges[u]){
        if(!instack[v] && dfn[v]){continue;}

        if(!dfn[v]){
            tarjan(v);
        }
        low[u]=min(low[u],low[v]);
    }
    if(dfn[u]==low[u]){
        vector<int>tmp;
        do{
            x=stk.top();
            stk.pop();
            instack[x]=false;
            tmp.push_back(x);
        }while(x!=u);
        scc.push_back(tmp);
    }
}

signed main(){
    int N,K;//point,edge
    while(cin>>N>>K){
        for(int i=0;i<K;++i){
            int s,e;
            cin>>s>>e;
            edges[s].push_back(e);
        }
        for(int i=0;i<N;++i){
            if(!dfn[i]){
                tarjan(i);
            }
        }

        for(const auto &c:scc){
            for(const auto &n:c){
                cout<<n<<' ';
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}