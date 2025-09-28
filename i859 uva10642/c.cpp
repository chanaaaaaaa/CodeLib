#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cout<<"Case "<<i<<": ";
        int x0,y0,xn,yn;
        cin>>x0>>y0>>xn>>yn;

        cout<<(long)(pow(xn+yn,2)-pow(x0+y0,2)+yn-y0+xn*3-x0*3)/2<<"\n";
    }
    return 0;
}
