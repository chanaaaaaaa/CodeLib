#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<string>
#include<iostream>
using namespace std;

signed main(){
    string IN;
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    while(cin>>IN){
        for(int i=0;i<IN.size();i++){
            cout<<char(int(IN[i])-7);
        }
        cout<<"\n";
    }
    return 0;
}
