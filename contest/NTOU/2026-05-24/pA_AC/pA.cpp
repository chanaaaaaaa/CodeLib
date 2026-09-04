#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    string s;
    while(cin >> n >> s){
        int k=(n+1)>>2;
        int res=1;
        for(int i=1;i<k;++i){
            char a=s[i-1],b=s[i];
            int w=(i<<2)+1;
            if(a==b){
                res+=2;
            }else if((a=='R' && b=='L') || (a=='L' && b=='R') ||
                       (a=='U' && b=='D') || (a=='D' && b=='U')) {
                res+=w<< 1;
            } else {
                res+=w+1;
            }
        }
        cout << res << '\n';
    }
    return 0;
}