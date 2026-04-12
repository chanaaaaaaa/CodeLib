#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

#define int long long
using namespace std;

signed main(void){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,K,gd,sr,bn;
    string S;
    while(cin>>N){
        gd=0;sr=0;bn=0;
        for(int i=0;i<N;i++){
            cin>>S>>K;
            if(K<=30){
                gd++;
            }else if(K<=50){
                sr++;
            }else if(K<=60){
                bn++;
            }
        }
        cout<<gd<<' '<<sr<<' '<<bn<<'\n';
    }
}
