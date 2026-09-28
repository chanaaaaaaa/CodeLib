#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <iostream>
#include <algorithm>
using namespace std;

int N,x,dat[3],tp;
signed main(){
    while(cin>>N){
        cin>>dat[0]>>dat[1]>>dat[2];
        sort(dat,dat+3,greater<int>());
        cout<<dat[2]<<'\n';

        if(N>3){
            for(int i=3;i<N;++i){
                cin>>tp;
                if(tp>dat[2]){
                    dat[2]=tp;
                    sort(dat,dat+3,greater<int>());
                }
                cout<<dat[2]<<'\n';
            }
        }
        cout<<'\n';
    }
    return 0;
}
