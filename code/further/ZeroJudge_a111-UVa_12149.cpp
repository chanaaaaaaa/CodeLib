#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    
    int a;
    while(cin>>a){
        if(a==0){break;}
        cout<<a*(a+1)*(a*2+1)/6<<"\n";
    }
    return 0;
}
