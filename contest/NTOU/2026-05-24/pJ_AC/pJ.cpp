#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}

signed main(){
    int n;
    while(n=read()){
        int m=read();
        int tot=2*n;
        vector<vector<int>>adj0(tot),adj1(tot);

        for(int i=0;i<n;++i){
            int c=read();
            int v=n+c-1;
            adj0[i].push_back(v);
            adj1[v].push_back(i);
        }
        for(int i=0;i<m;++i){
            int u=read()-1,v=read()-1;
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        const int INF=1e9;
        vector<int>dist(tot,INF);
        dist[0]=0;
        deque<int>dq;
        dq.push_front(0);

        while(!dq.empty()){
            int u=dq.front();
            dq.pop_front();
            for(int v:adj0[u]){
                if(dist[v]>dist[u]){
                    dist[v]=dist[u];
                    dq.push_front(v);
                }
            }
            for(int v:adj1[u]){
                if(dist[v]>dist[u]+1){
                    dist[v]=dist[u]+1;
                    dq.push_back(v);
                }
            }
        }

        if(dist[n-1]>=INF){
            puts("-1");
        }else{
            printf("%d\n",dist[n-1]);
        }
    }
    return 0;
}
