#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b){
        if(a+b==-2){break;}
        a=abs(a-b);
        b=100-a;
        if(b>a){
            cout<<a<<"\n";
        }else{
            cout<<b<<"\n";
        }
    }
    return 0;
}
