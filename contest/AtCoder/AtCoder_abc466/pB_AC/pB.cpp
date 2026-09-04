#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

signed main(){
    int N,M;
    while(cin>>N>>M){
        vector<int>dat(M,-1);
        int c,s;
        while(N--){
            cin>>c>>s;
            dat[c-1]=max(dat[c-1],s);
        }

        for(int i=0;i<M;++i){
            cout<<dat[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
