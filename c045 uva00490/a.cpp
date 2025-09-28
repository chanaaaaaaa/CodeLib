#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;
string A[100];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int line=0,maxx=0;
    while(getline(cin,A[line])){
        if(A[line].size()>maxx) maxx=A[line].size();
        line++;
    }
    for(int i=0;i<maxx;i++){
        for(int j=line-1;j>=0;j--){
            if(i>=A[j].size()) cout<<" ";
            else cout<<A[j][i];
        }
        cout<<"\n";
    }

    return 0;
}
