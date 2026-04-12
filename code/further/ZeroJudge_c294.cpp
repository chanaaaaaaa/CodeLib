#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    vector<int>dat;
    for(int i=0;i<3;i++){
        int x;
        cin>>x;
        dat.push_back(x);
    }
    sort(dat.begin(),dat.end());
    cout<<dat[0]<<" "<<dat[1]<<" "<<dat[2]<<"\n";
    if(dat[0]+dat[1]<=dat[2]){
        cout<<"No\n";
        return 0;
    }

    dat[2]*=dat[2];
    dat[0]=dat[0]*dat[0]+dat[1]*dat[1];
    if(dat[2]>dat[0])cout<<"Obtuse\n";
    else if(dat[2]<dat[0])cout<<"Acute\n";
    else cout<<"Right\n";
    return 0;
}
