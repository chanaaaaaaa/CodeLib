#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
using namespace std;

int N,K,x;
set<int>dat;

bool check(int ran){
    int now=0,times=0;
    for(auto &s : dat){
        if(s>now){
            now=s+ran;
            times++;
            if(times>K){break;}
        }
    }
    return times<=K;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //init
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>x;
        dat.insert(x);
    }
    //doing
    int l=1,r=1e9;
    while(l<r){
        if(r==l+1){
            if(!check(l))l=r;
            break;
        }else{
            x=(l+r)/2;
            if(check(x))r=x;
            else l=x+1;
        }
    }
    cout<<l<<"\n";
    return 0;
}
