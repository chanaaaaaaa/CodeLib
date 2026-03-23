#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")

#include<iostream>
#include<string>
#include<math.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string IN;
        getline(cin,IN);
        int l=sqrt(IN.size());
        if(sqrt(IN.size())!=l){cout<<"INVALID\n";continue;}
        char mp[l][l];
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                mp[i][j]=IN[i*l+j];
            }
        }

        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                cout<<mp[j][i];
            }
        }
        cout<<"\n";
    }
    return 0;
}
