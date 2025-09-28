#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    long long a,b;
    while(cin>>a>>b){
        if(b==0 || b==1){
            cout<<"Boring!"<<"\n";
            continue;
        }
        for(int i=0;i<1000;i++){
            if(pow(b,i)==a){
                while(a!=1){
                    cout<<a<<" ";
                    a/=b;
                }
                cout<<"1"<<"\n";
                break;
            }else if(pow(b,i)>a){
                cout<<"Boring!"<<"\n";
                break;
            }
        }
    }

    return 0;
}
