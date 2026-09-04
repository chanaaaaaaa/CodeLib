#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

inline bool cmp(pair<int,char>&a,pair<int,char>&b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}

signed main(){
    vector<pair<int,char>>dat(10);
    for(int i=0;i<10;++i){
        dat[i].first=0;
        dat[i].second='A'+i;
    }

    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        string S;
        cin>>S;
        for(int j=0;j<10;++j){
            if(S[j]=='O'){
                ++dat[j].first;
            }
        }
    }
    sort(dat.begin(),dat.end(),cmp);
    for(pair<int,char>p:dat){
        cout<<p.second;
    }
    cout<<'\n';
}
