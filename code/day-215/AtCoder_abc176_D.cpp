#include <iostream>
#include <queue>
#include <utility>
#include <climits>

#define int long long
using namespace std;

const int MAXN=1e3+10;
const int INF=1e18;
const int d[4][2]={
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};
char mp[MAXN][MAXN]={0};
int dist[MAXN][MAXN];

int H,W,sx,sy,ex,ey;

inline int bfs(){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>PQ;

    dist[sx][sy]=0;
    PQ.push({0,{sx,sy}});

    while(!PQ.empty()){
        int w=PQ.top().first;
        int x=PQ.top().second.first;
        int y=PQ.top().second.second;
        PQ.pop();

        if(w>dist[x][y]){continue;}
        //judge
        if(x==ex && y==ey){
            return w;
        }
        //-judge
        //walk
        for(int f=0;f<4;++f){
            int nx=x+d[f][0],ny=y+d[f][1];
            if(nx>=0 && nx<H && ny>=0 && ny<W){
                if(mp[nx][ny]=='.' && dist[nx][ny]>dist[x][y]){
                    dist[nx][ny]=dist[x][y];
                    PQ.push({dist[nx][ny],{nx,ny}});
                }
            }
        }
        //-walk
        //jump
        for(int i=-2;i<=2;++i){
            for(int j=-2;j<=2;++j){
                int nx=x+i,ny=y+j;
                if(nx>=0 && nx<H && ny>=0 && ny<W){
                    if(mp[nx][ny]=='.' && dist[nx][ny]>dist[x][y]+1){
                        dist[nx][ny]=dist[x][y]+1;
                        PQ.push({dist[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        //-jump

    }
    return -1;
}

signed main(){
    cin>>H>>W;
    cin>>sx>>sy;
    cin>>ex>>ey;
    --sx;--sy;
    --ex;--ey;
    for(int i=0;i<H;++i){
        cin>>mp[i];
    }
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            dist[i][j]=INF;
        }
    }
    cout<<bfs()<<'\n';
    return 0;
}
