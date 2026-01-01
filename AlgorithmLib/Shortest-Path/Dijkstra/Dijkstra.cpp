#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN=1e5+50;

int T,N,M,
    d[2][4]={
        {1,-1,0,0},
        {0,0,1,-1}
    };
vector<vector<int>>grid(MAXN,vector<int>(MAXN,0));
vector<vector<int>>vals(MAXN,vector<int>(MAXN,0));
vector<vector<bool>>vis(MAXN,vector<bool>(MAXN,0));
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
inline void solve(){
    vals[0][0]=grid[0][0];
    pq.push({grid[0][0],{0,0}});

    while(!pq.empty()){
        int val=pq.top().first,
            x=pq.top().second.first,
            y=pq.top().second.second;
        pq.pop();
        vis[x][y]=true;

        for(int f=0;f<4;++f){
            int nx=x+d[0][f],
                ny=y+d[1][f];
            
            if(nx>0 && nx<N && ny>0 && ny<M && !vis[nx][ny]){
                int nv=grid[nx][ny]+val;
                if(vals[nx][ny]>nv || vals[nx][ny]==-1){
                    vals[nx][ny]=nv;
                    pq.push({nv,{nx,ny}});
                }
            }
        }
    }
}


signed main(){
    int T;
    cin>>T;
    while(--T){
        cin>>N>>M;
        grid.assign(MAXN,vector<int>(MAXN,0));
        vis.assign(MAXN,vector<bool>(MAXN,0));
        vals.assign(MAXN,vector<int>(MAXN,-1));

        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                int tmp;
                cin>>tmp;
                grid[i][j]=tmp;
            }
        }

        solve();
        cout<<vals[N-1][M-1]<<'\n';  
    }
    return 0;
}