#include <iostream>

using namespace std;

signed main(){
    int N;
    while(cin>>N){
        if(N==0){break;}
        int xr=0,a;
        for(int i=0;i<N;++i){
            cin>>a;
            xr^=a;
        }
        if(xr!=0){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}
