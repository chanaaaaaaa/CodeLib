#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int A,B;
    while(cin>>A>>B){
        if(A+B==0){break;}
        int a=ceil(sqrt(A));
        B=floor(sqrt(B));
        if(a==ceil(sqrt(A)))a--;
        cout<<B-a<<"\n";
    }
    return 0;
}
