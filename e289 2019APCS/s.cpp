#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m,n,type=0,Ans=0;
    vector<string>v;
    unordered_map<string,int>mp;

    cin>>m>>n;
    v.reserve(n+1);
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<m;i++){
        if(mp[v[i]]==0){
            type++;
        }
        mp[v[i]]++;
    }
    if(type==m)Ans++;

    for(int i=m;i<n;i++){
        mp[v[i-m]]--;
        if(mp[v[i-m]]==0)type--;
        if(mp[v[i]]==0)type++;
        mp[v[i]]++;
        if(type==m)Ans++;
    }
    cout<<Ans<<"\n";
    return 0;
}
