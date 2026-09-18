#include <iostream>

using namespace std;

signed main(){
    int N;
    while(cin>>N){
        if(N<3 || N>18){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
        }
    }
    return 0;
}
