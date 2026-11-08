#include <iostream>
#include <vector>
using namespace std;

const int MAXN=300+20;
int N,T,K,time,egg;

vector<int>dp;
signed main(){
    while(cin>>N>>T>>K){
        dp.assign(T+5,0);
        for(int i=0;i<N;++i){
            cin>>time>>egg;
            time<<=1;
            for(int i=T-time;i>=0;--i){
                int nxt=i+time;
                if(nxt>T){break;}

                dp[nxt]=max(dp[nxt],dp[i]+egg);
            }
            //
            for(int i=0;i<T;++i){
                cout<<dp[i]<<' ';
            }
            cout<<' ';
            //
        }
        int maxx=0;
        for(int i=0;i<T;++i){
            maxx=max(maxx,dp[i]);
        }
        cout<<maxx<<'\n';
    }
    return 0;
}
/*
5 35 10
16 2
1 6
4 5
5 6
17 5
*/
