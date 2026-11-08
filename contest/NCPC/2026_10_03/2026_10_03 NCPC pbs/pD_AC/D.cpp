#include <iostream>
#include <utility>
#include <queue>
#include <unordered_set>
#include <map>
#include <vector>
#include <climits>

#define int long long
using namespace std;

//st:{node,deg}
//ed:{node,deg}
//w:w
//
//map[st]={ed,w}

//pair<int,int>
//vector<pair<pair<int,int>,int>>
map<pair<int,int>,vector<pair<pair<int,int>,int>>>mp;

unordered_set<int>start,enddd;//deg
vector<vector<int>>dist;
int N,M,K,Q;
int u,v,d,w,n;
signed main(){
    while(cin>>N>>M>>K>>Q){
        start.clear();enddd.clear();
        dist.assign(K+1,vector<int>(N+1,LLONG_MAX));

        for(int i=0;i<M;++i){
            cin>>u>>v>>d>>w;
            mp[{u,d}].push_back({{v,d},w});

            if(u==1){
                start.emplace(d);
            }
            if(v==N){
                enddd.emplace(d);
            }
        }

        for(int i=0;i<Q;++i){
            cin>>n>>u>>v>>w;
            mp[{n,u}].push_back({{n,v},w});
        }
        //-input

        //st:{node,deg}
        //PQ:{w,{st}}

        //pair<int,int>
        //pair<int,pair<int,int>>
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>PQ;
        for(int i:start){
            PQ.push({0,{1,i}});
            dist[i][1]=0;
        }

        //cout<<'k';
        while(!PQ.empty()){
            int w=PQ.top().first;
            int st_nde=PQ.top().second.first;
            int st_deg=PQ.top().second.second;
            PQ.pop();

            if(dist[st_deg][st_nde]!=w){continue;}

            //cout<<st_nde<<' '<<st_deg<<'\n';
            for(pair<pair<int,int>,int> &piii:mp[{st_nde,st_deg}]){
                int ed_nde=piii.first.first;
                int ed_deg=piii.first.second;
                int nw=w+piii.second;

                if(dist[ed_deg][ed_nde] > nw){
                    dist[ed_deg][ed_nde]=nw;
                    PQ.push({nw,{ed_nde,ed_deg}});
                }
                //cout<<ed_nde<<' '<<ed_deg<<' '<<nw<<'\n';
            }
            //cout<<'\n';
        }

        int minn=LLONG_MAX;
        for(int d:enddd){
            minn=min(minn,dist[d][N]);
        }

        if(minn==LLONG_MAX){
            cout<<"-1\n";
        }else{
            cout<<minn<<'\n';
        }
    }
    return 0;
}
/*
5 6 3 3
1 2 1 4
2 5 1 10
1 3 2 2
3 4 2 2
2 4 1 2
4 5 3 2
4 2 3 3
4 1 3 1
3 2 1 10
*/
