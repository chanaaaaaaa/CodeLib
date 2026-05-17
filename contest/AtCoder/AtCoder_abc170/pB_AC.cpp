#include <iostream>

using namespace std;

signed main(){
    int N,M;
    cin>>N>>M;

    if(N*2>M || N*4<M || M&1){
        cout<<"No\n";
    }else{
        cout<<"Yes\n";
    }

    return 0;
}
