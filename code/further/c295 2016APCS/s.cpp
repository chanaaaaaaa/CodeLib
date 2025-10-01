#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    vector<int>dat;
    int a,b,sum=0;
    cin>>a>>b;
    while(a--){
        int maxx=0;
        for(int i=0;i<b;i++){
            int temp;
            cin>>temp;
            maxx=max(maxx,temp);
        }
        sum+=maxx;
        dat.push_back(maxx);
    }
    bool flag=true;
    cout<<sum<<"\n";
    int maxx=dat.size()-1;
    for(;maxx>=0;maxx--){
        if(sum%dat[maxx]==0)break;
    }
    for(int i=0;i<=maxx;i++){
        if(sum%dat[i]==0){
            cout<<dat[i];
            flag=false;
            if(i!=maxx)cout<<" ";
        }
    }
    if(flag)cout<<"-1";
    return 0;
}
