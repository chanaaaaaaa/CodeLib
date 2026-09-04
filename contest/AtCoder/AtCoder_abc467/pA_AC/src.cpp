#include <iostream>

using namespace std;

signed main(){
    double H,W;
    while(cin>>H>>W){
        if(W/H/H>=0.0025){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}
