#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N,total=0;
    while(cin>>N){
        total=N;
        while(N>=3){
            int temp=N/3;
            total+=temp;
            N-=temp*2;
        }
        if(N==2){
            cout<<total+1<<"\n";
        }else{
            cout<<total<<"\n";
        }
    }
    return 0;
}
