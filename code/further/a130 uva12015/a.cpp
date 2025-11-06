#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T,cases=0;
    cin>>T;
    while(T--){
        string IN;
        int num,mx=0;
        vector<pair<string,int>>mp;
        for(int i=0;i<10;i++){
            cin>>IN>>num;
            mp.push_back({IN,num});
            if(num>mx){mx=num;}
        }
        cout<<"Case #"<<++cases<<":\n";
        for(auto it:mp){
            if(it.second==mx){
                cout<<it.first<<"\n";
            }
        }
    }
    return 0;
}
