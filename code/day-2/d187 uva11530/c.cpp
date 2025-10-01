#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")

#include<iostream>

using namespace std;

signed main() {
    int t;
    cin>>t;
    cin.ignore();

    for(int i=1;i<=t;i++){
        string A;
        getline(cin,A);

        int con=0;
        for(int i=0;i<A.size();i++){
            int n=A[i];
            if(n==' '){con++;}
            else{
                con+=min(n%'a',min(n%'d',min(n%'g',min(n%'j',min(n%'m',min(n%'p',min(n%'t',n%'w')))))))+1;
            }
        }
        cout<<"Case #"<<i<<": "<<con<<"\n";
    }
    return 0;
}
