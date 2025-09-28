#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int a;
    while(cin>>a){
        int out=0;
        for(int i=1;i<=a;i++){
            out+=pow(i,2);
        }
        if(out!=0){cout<<out<<"\n";}
        else{cout<<"\n";}
    }
    return 0;
}
