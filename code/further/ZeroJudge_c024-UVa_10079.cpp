#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    long N;
    while(cin>>N){
        if(N<0){break;}
        cout<<N*(N+1)/2+1<<"\n";
    }
    return 0;
}
