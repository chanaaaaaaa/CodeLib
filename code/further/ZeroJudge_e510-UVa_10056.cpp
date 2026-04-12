#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int S;
    cin>>S;
    while(S--){
        int N,i;
        double p,Ans;
        cin>>N>>p>>i;
        if(p==0.0){
            cout<<fixed<<setprecision(4)<<"0.0000"<<"\n";
            continue;
        }
        Ans=(p*pow(1-p,i-1))/(1-pow(1-p,N));
        cout<<fixed<<setprecision(4)<<Ans<<"\n";
    }
    return 0;
}
