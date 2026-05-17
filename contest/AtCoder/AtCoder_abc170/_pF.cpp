#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const int INF=0x3f3f3f3f;


inline int dijk(){
    int H,W,K;
    cin>>H>>W>>K;
    int sx,sy,ex,ey;
    cin>>sx>>sy>>ex>>ey;

    vector<string>mp(H);
    for(int i=0;i<H;++i){
        cin>>mp[i];
    }

    vector<pair<pair<int,int>,int>>d;
    d.push_back({{1,0},1});
    d.push_back({{-1,0},1});
    d.push_back({{0,1},1});
    d.push_back({{0,-1},1});

    vector<vector<int>>dis(H,vector<int>(W,INF));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>PQ();

    dis[sx][sy]=0;
    PQ.push(make_pair(0,make_pair(sx,sy)));
    while(!PQ.empty()){
        int dt=PQ.top().first.first;
        int x=PQ.top().second.first;
        int y=PQ.top().second.second;
        PQ.pop();

        if(dt>dis[x][y]){continue;}
        for(int f=0;f<4;++f){
            for(int k=1;k<=K;++k){
                int nx=x+k*d[f].first.first;
                int ny=y+k*d[f].first.second;
                if(nx<0 || nx>=H){break;}
                if(ny<0 || ny>=W){break;}
                if(mp[nx][ny]=='@'){break;}
                if(dis[nx][ny]<dt+d[f].second){break;}
                if(dis[nx][ny]>dt+d[f].second){
                    dis[nx][ny]=dt+d[f].second;
                    PQ.push({dis[nx][ny],{nx,ny});
                }
            }
        }
    }

    if(dis[ex][ey]==INF){
        putchar('-');
        putchar('1');
    }else{
        write(dis[ex][ey]);
    }
    putcahr('\n');

    return;
}
signed main(){
    dijk();
    return 0;
}
