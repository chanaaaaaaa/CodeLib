#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin>>N;
    while(N--){
        long long a,b;
        cin>>a>>b;
        if(a>b){
            cout<<">\n";
        }else if(a<b){
            cout<<"<\n";
        }else{
            cout<<"=\n";
        }
    }
    return 0;
}
