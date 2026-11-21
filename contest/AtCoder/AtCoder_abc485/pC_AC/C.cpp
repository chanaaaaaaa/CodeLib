#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

signed main() {
    int N;
    while(cin>>N){
        vector<int>C(N);
        for(int i=0;i<N;++i){cin>>C[i];}

        const int INF=1e9;
        vector<int>ans(N,INF);

        int last_diff=-1;
        for(int i=1;i<N;++i){
            if(C[i]!=C[i-1]){last_diff=i-1;}

            if(last_diff!=-1){
                ans[i]=min(ans[i],i-last_diff);
            }
        }

        last_diff=-1;
        for(int i=N-2;i>=0;--i){
            if(C[i]!=C[i+1]){last_diff=i+1;}

            if(last_diff!=-1){
                ans[i]=min(ans[i],last_diff-i);
            }
        }

        for(int i=0;i<N;++i){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
