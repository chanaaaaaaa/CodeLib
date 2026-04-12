#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N,M,K;
    vector<int>dat;
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++){
        dat.push_back(i);
    }
    N=0;
    M--;
    while(K--){
        N=(N+M)%dat.size();
        dat.erase(dat.begin()+N);
        N%=dat.size();
    }
    cout<<dat[N];
    return 0;
}
