#include <iostream>
#include <vector>

using namespace std;

signed main(){
    int T;
    while(cin>>T){
        vector<int>dat(T,0);
        for(int i=0;i<T;++i){
            cin>>dat[i];
        }

        vector<int>dp(T,1);
        int res=0;

        for(int i=0;i<T-1;++i){
            for(int j=i+1;j<T;++j){
                if(dat[j] > dat[i]){
                    dp[j]=max(dp[j],dp[i]+1);
                    res=max(res,dp[j]);
                }
            }
        }
        cout<<'\n'<<res<<'\n';
    }
    return 0;
}
