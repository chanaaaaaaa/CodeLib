#include <iostream>

using namespace std;

signed main(){
    int N,M;
    while(cin>>N>>M){
        if(N*M<0){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
        }
    }
    return 0;
}
