#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#define int long long
using namespace std;

pair<int,int>routes[1000000];
int N,M,a,b,c,goods[1999999],Ques[10000];

int init(int id){
    if(id>=N) return goods[id];
    goods[id]=init(routes[id].first)+init(routes[id].second);
    return goods[id];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=N;i<N*2;i++){
        cin>>goods[i];
    }
    for(int i=0;i<M;i++){
        cin>>Ques[i];
    }
    for(int i=1;i<N;i++){
        cin>>a>>b>>c;
        routes[a]={b,c};
    }
    a=init(1);

    for(int i=0;i<M;i++){
        int np=1;
        while(np<N){
            if(goods[routes[np].first]>goods[routes[np].second]){
                np=routes[np].second;
            }else{np=routes[np].first;}
            goods[np]+=Ques[i];
        }
        cout<<np<<" ";
    }
    return 0;
}
