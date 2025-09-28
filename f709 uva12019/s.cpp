#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int N,init=5,m,d;
int md[12]={0,31,59,90,120,151,181,212,243,273,304,334};

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>N;
    while(N--){
        cin>>m>>d;
        int out=(init+md[m-1]+d)%7;
        if(out==0){
            cout<<"Sunday\n";
        }else if(out==1){
            cout<<"Monday\n";
        }else if(out==2){
            cout<<"Tuesday\n";
        }else if(out==3){
            cout<<"Wednesday\n";
        }else if(out==4){
            cout<<"Thursday\n";
        }else if(out==5){
            cout<<"Friday\n";
        }else if(out==6){
            cout<<"Saturday\n";
        }
    }
    return 0;
}
