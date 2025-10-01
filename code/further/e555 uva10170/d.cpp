#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    long long S,D;
    while(cin>>S>>D){
        while(D>0){
            D-=S;
            S++;
        }
        cout<<S<<"\n";
    }
    return 0;
}
