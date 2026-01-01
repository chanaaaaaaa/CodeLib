#include <iostream>
#include <vector>
using namespace std;

signed main(){
    int N,K,A;//point,edge,query
    while(cin>>N>>K>>A && (N||K)){
        vector<vector<long long>>grid(N,vector<long long>(N,0x7fffffff));

        while(K--){
            int s,t,w;//start,end,weight
            cin>>s>>t>>w;
            grid[s][t]=grid[t][s]=w;
        }

        for(int k=0;k<N;++k){
            for(int i=0;i<N;++i){
                for(int j=0;j<N;++j){
                    grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);
                }   
            }
        }

        while(A--){
            int s,t;
            cin>>s>>t;
            cout<<grid[s][t]<<'\n';
        }
    }
    return 0;
}
