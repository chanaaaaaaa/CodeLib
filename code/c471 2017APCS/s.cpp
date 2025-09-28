#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
#define int long long
using namespace std;

pair<int,int>wt[100000+10];//weight,times
int N,Ans=0;

bool cmp(pair<int,int>a,pair<int,int>b){
    return a.first*b.second < b.first*a.second;
}

signed main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    //init
    cin>>N;
    for(int i=0;i<N;i++)cin>>wt[i].first;
    for(int i=0;i<N;i++)cin>>wt[i].second;
    //doing
    /*
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(wt[i].first*wt[j].second>wt[j].first*wt[i].second){
                swap(wt[i],wt[j]);
            }
        }
    }*/
    sort(wt,wt+N,cmp);


    for(int i=N-1;i>=0;i--){
        wt[i].second+=wt[i+1].second;
        Ans+=wt[i].first*wt[i+1].second;
    }

    cout<<Ans<<"\n";
    return 0;
}
