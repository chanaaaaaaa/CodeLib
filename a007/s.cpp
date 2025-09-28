#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    vector<int>ze;
    for(int i=2;i<65535;i++){
        bool flag=true;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                flag=false;
                break;
            }
        }
        if(flag){
            ze.push_back(i);
        }
    }
    int A;
    while(cin>>A){
        bool flag=true;
        int maxx=sqrt(A);
        for(int i=0;i<ze.size();i++){
            if(ze[i]>maxx){
                break;
            }
            if(A%ze[i]==0){
                flag=false;
                break;
            }
        }
        if(flag){cout<<"質數\n";}
        else{cout<<"非質數\n";}
    }


    return 0;
}
