#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        int a,b;
        cin>>a>>b;
        if((a&1)==0){a++;}
        if((b&1)==0){b--;}
        cout<<"Case "<<i<<": "<<(a+b)*(b-a+2)/4<<"\n";
    }
    return 0;
}
