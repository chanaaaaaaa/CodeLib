#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

signed main(){
    int N,cnt;
    while(cin>>N){
        unordered_map<string,int>dat;
        string S;
        cnt=1;
        for(int i=0;i<N;++i){
            cin>>S;
            if(dat[S]==0){
                dat[S]=cnt;
                cout<<cnt<<'\n';
                ++cnt;
            }else{
                cout<<dat[S]<<'\n';
            }
        }
    }
    return 0;
}
