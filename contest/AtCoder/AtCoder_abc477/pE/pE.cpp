#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

signed main(){
    int T,N,M,u,v,Q;
    while(cin>>T){
        while(T--){
            unordered_map<pair<int,int>,bool>edges;
            cin>>N>>M;

            for(int i=0;i<M;++i){
                cin>>u>>v;
                edges[{u,v}]=true;
                edges[{v,u}]=true;
            }

            cin>>Q;
            for(int i=0;i<Q;++i){

            }
        }
    }
    return 0;
}
