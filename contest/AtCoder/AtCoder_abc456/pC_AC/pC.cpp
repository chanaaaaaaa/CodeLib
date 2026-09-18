#include <iostream>
#include <string>
#include <unordered_map>

#define int long long
using namespace std;

const int MOD=998244353;

signed main(){
    string S;
    cin>>S;
    int res=0;

    unordered_map<char,int>dp;
    for(char c:S){
        dp[c]=(dp['a']+dp['b']+dp['c']+1)%MOD;
    }

    for(unordered_map<char,int>::iterator it=dp.begin();it!=dp.end();++it){
        res+=it->second;
    }
    cout<<res%MOD<<'\n';
    return 0;
}
