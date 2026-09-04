#include <iostream>
#include <vector>
using namespace std;

signed main(){
    int N,k;
    bool f;
    vector<int>dat;
    while(cin>>N){
        f=true;
        dat.assign(N+1,0);
        for(int i=1;i<=N;++i){
            cin>>dat[i];
        }
        for(int i=1;i<=N;++i){
            cin>>k;
            if(dat[k]!=i){f=false;}
        }
        if(f){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}
