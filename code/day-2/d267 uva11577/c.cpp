#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")

#include<iostream>
#include<math.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        int dic[26]={0};
        string A;
        getline(cin,A);
        for(int i=0;i<A.size();i++){
            if(A[i]<='z' && A[i]>='a'){
                dic[A[i]-'a']++;
            }else if(A[i]<='Z' && A[i]>='A'){
                dic[A[i]-'A']++;
            }
        }

        int maxx=-1;
        for(int i=0;i<26;i++){
            if(dic[i]>maxx){maxx=dic[i];}
        }
        for(int i=0;i<26;i++){
            if(dic[i]==maxx){cout<<char('a'+i);}
        }
        cout<<'\n';
    }
    return 0;
}
