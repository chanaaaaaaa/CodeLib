#pragma("Ofast")
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

vector<pair<pair<int,int>,int>>dat;
map<pair<int,int>,int>mp;
int N,st,ed,w;
signed main(){
    while(cin>>N){
        dat.assign(N,pair<pair<int,int>,int>());
        mp.clear();

        for(int i=0;i<N;++i){
            cin>>st>>ed>>w;

            for(map<pair<int,int>,int>::iterator it=mp.begin();it!=mp.end();++it){
                int m_st=it->first.first;
                int m_ed=it->first.second;

                if(st>m_ed || m_st>ed){
                    mp[{min(st,m_st),max(ed,m_ed)}]=max(mp[{min(st,m_st),max(ed,m_ed)}],it->second+w);
                    //cout<<st<<' '<<ed<<' '<<m_st<<' '<<m_ed<<'\n';
                }
            }
            mp[{st,ed}]=w;
        }

        int maxx=0;
        for(map<pair<int,int>,int>::iterator it=mp.begin();it!=mp.end();++it){
            maxx=max(maxx,it->second);
        }
        cout<<maxx<<'\n';
    }
    return 0;
}
/*
4
1 3 5
2 5 6
4 7 5
6 9 4
*/
/*
3
1 2 3
2 3 4
3 4 5
*/
