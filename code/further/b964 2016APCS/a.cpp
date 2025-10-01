#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    vector<int>dat;
    int N;
    cin>>N;
    while(N--){
        int temp;
        cin>>temp;
        dat.push_back(temp);
    }
    int inside=101,outside=-1;//60
    sort(dat.begin(),dat.end());
    for(const auto &s :dat){
        if(s<60 && s>outside)outside=s;
        else if(s>=60 && s<inside)inside=s;
        cout<<s<<" ";
    }
    cout<<"\n";
    if(outside==-1)cout<<"best case\n";
    else cout<<outside<<"\n";
    if(inside==101)cout<<"worst case\n";
    else cout<<inside<<"\n";
    return 0;
}
