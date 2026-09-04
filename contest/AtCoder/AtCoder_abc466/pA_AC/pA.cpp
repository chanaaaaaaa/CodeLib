#include <iostream>

using namespace std;

signed main(){
    int N;
    while(cin>>N){
        bool f=true;
        int a;
        while(N--){
            cin>>a;
            if(a>=0){
                f=false;
            }
        }
        if(!f){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
        }
    }
    return 0;
}
