#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int v[100000];
    int M,S,N,now=0;
    cin>>M>>S>>N;
    for(int i=0;i<N;i++){
        cin>>v[i];
        now+=v[i];
    }
    int target=S-M+now;
    if(target<=0){cout<<"0\n";return 0;}

    map<int,int>mp;
    for(int i=0;i<N;i++){
        now=v[i];
        for(int j=target;j>0;j--){
            if(mp[j]>0){
                mp[j+now]++;
                if(now+j==target){
                    cout<<target<<"\n";
                    return 0;
                }
            }
        }
        mp[now]++;
    }
    for(auto it:mp){
        if(it.first>=target && it.second>0){
            cout<<it.first<<"\n";
            break;
        }
    }
    return 0;
}
