#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string A,B;
    while(cin>>A>>B){
        multiset<int>same;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                if(A[i]==B[j]){
                    B[j]='\0';
                    same.insert(int(A[i]));
                    break;
                }
            }
        }
        for(const auto &s : same){
            cout<<char(s);
        }
        cout<<"\n";
    }
    return 0;
}
