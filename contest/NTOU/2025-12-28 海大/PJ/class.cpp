#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<cstdio>
#include<vector>
#include<queue>

#define int long long
using namespace std;

inline int read(){
    int x=0;char c=0;
    while(c<'0'||c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}

signed main(void){
    int n;
    while(n=read()){
        if(n<=2){
            printf("Yes\n");
            continue;
        }

        vector<vector<int>>adj(n+1);
        vector<int>deg(n+1,0);

        for(int i=0;i<n-1;i++){
            int u=read(),v=read();
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;deg[v]++;
        }

        vector<bool>removed(n+1,0);
        queue<int>q;


        for(int i=1;i<=n;i++){
            if(deg[i]==1){q.push(i);}
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(removed[u]){continue;}
            removed[u]=true;

            for(int v:adj[u]){
                if(!removed[v]){
                    deg[v]--;
                    if(deg[v]==1){q.push(v);}
                }
            }
        }

        for(int i=1;i<=n;i++){
            if(!removed[i]&&deg[i]>2){
                printf("No\n");
                continue;
            }
        }

        int remaining=0,start=-1;
        for(int i=1;i<=n;i++){
            if(!removed[i]){
                remaining++;
                if(start==-1){start=i;}
            }
        }

        if(remaining<=1){
            printf("Yes\n");
            continue;
        }

        vector<bool>vis(n+1,0);
        queue<int>bfs;
        bfs.push(start);
        vis[start]=true;
        int visited=1;

        while(!bfs.empty()){
            int u=bfs.front();
            bfs.pop();
            for(int v:adj[u]){
                if(!removed[v]&&!vis[v]){
                    vis[v]=true;
                    bfs.push(v);
                    visited++;
                }
            }
        }

        if(visited==remaining){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}
/*
7
1 2
2 3
3 4
2 5
3 6
3 7

10
1 2
2 5
5 6
1 3
3 7
7 8
1 4
4 9
9 10
*/
