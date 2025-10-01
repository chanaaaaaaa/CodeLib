#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int a1,a2,c;
    while(cin>>a1>>a2>>c){
        bool flag=true;
        if((a1!=0 && a2!=0 && c==1) || ((a1==0 || a2==0) && c==0)){
            cout<<"AND\n";
            flag=false;
        }
        if(((a1!=0 || a2!=0) && c==1)||(a1==0 && a2==0 && c==0)){
            cout<<"OR\n";
            flag=false;
        }
        if(((a1!=0 && a2==0)||(a1==0 && a2!=0))&&(c==1)||((a1==0 && a2==0)||(a1!=0 && a2!=0))&&(c==0)){
            cout<<"XOR\n";
            flag=false;
        }
        if(flag){
            cout<<"IMPOSSIBLE\n";
        }
    }
    return 0;
}
