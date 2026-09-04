#include <set>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N,M,res;
set<int>Lx,Ly;
vector<pair<int,int>>dat;
signed main(){
    while(cin>>N>>M){
        res=0;
        Lx.clear();
        Ly.clear();
        dat.assign(M,pair<int,int>());
        for(int i=0;i<M;++i){
            cin>>dat[i].first>>dat[i].second;
        }
        for(int i=M-1;i>=0;--i){
            if(!Ly.count(dat[i].second) && !Lx.count(dat[i].first)){
                ++res;
            }
            Lx.insert(dat[i].first);
            Ly.insert(dat[i].second);
        }
        cout<<res<<'\n';
    }
    return 0;
}
