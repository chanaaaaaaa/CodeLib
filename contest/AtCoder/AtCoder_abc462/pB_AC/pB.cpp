#include <iostream>
#include <vector>
using namespace std;

signed main(){

    int N,K,A;
    while(cin>>N){
        vector<vector<int>>dat(N+1,vector<int>());
        for(int i=1;i<=N;++i){
            cin>>K;
            while(K--){
                cin>>A;
                dat[A].push_back(i);
            }
        }

        for(int i=1;i<=N;++i){
            cout<<dat[i].size();
            for(int num:dat[i]){
                cout<<' '<<num;
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}
