#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    long A;
    while(cin>>A){
        if(A==0){break;}
        while(A>9){
            for(int i=1;i<=9;i++){
                if(A>=pow(10,i)){
                    int temp=A/pow(10,i);
                    A-=(temp%10)*pow(10,i);
                    A+=(temp%10);
                }
            }
        }
        cout<<A<<"\n";
    }
    return 0;
}
