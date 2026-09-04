#include <iostream>
#include <string>
#include <cmath>

#define int long long
using namespace std;

const int MAXN=2e5+20;
string S;

int numx[MAXN],numy[MAXN];
int T,N;
signed main(){
    while(cin>>T){
        while(T--){
            cin>>N>>S;
            for(int i=0;i<N;++i){cin>>numx[i];}
            for(int i=1;i<N;++i){cin>>numy[i];}
            //solve
            int dp[N+1][2];
            dp[0][0]=0;
            dp[0][1]=-numx[0];

            for(int i=1;i<N;++i){
                if(S[i-1]=='S' && S[i]=='S'){
                    //dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
                    //dp[i][1]=dp[i-1][0]-numx[i];
                    dp[i][0]=max(dp[i-1][0],dp[i-1][1]+numy[i]);
                    dp[i][1]=max(dp[i-1][0]-numx[i],dp[i-1][1]-numx[i]);
                }else if(S[i-1]=='S' && S[i]=='R'){
                    //dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
                    //dp[i][1]=dp[i-1][0]-numx[i];
                    dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
                    dp[i][1]=max(dp[i-1][0]-numx[i],dp[i-1][1]-numx[i]+numy[i]);
                }else if(S[i-1]=='R' && S[i]=='S'){
                    //dp[i][0]=max(dp[i-1][0],dp[i-1][1])+numy[i];
                    //dp[i][1]=dp[i-1][0]-numx[i];
                    dp[i][0]=max(dp[i-1][0]+numy[i],dp[i-1][1]);
                    dp[i][1]=max(dp[i-1][0]-numx[i],dp[i-1][1]-numx[i]);
                }else if(S[i-1]=='R' && S[i]=='R'){
                    //dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
                    //dp[i][1]=dp[i-1][0]-numx[i]+numy[i];
                    dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
                    dp[i][1]=max(dp[i-1][0]-numx[i]+numy[i],dp[i-1][1]-numx[i]);
                }
            }
            /*
            for(int i=0;i<N;++i){
                cout<<dp[i][0]<<' ';
            }
            cout<<'\n';
            for(int i=0;i<N;++i){
                cout<<dp[i][1]<<' ';
            }
            cout<<'\n';
            */
            cout<<max(dp[N-1][0],dp[N-1][1])<<'\n';
        }
    }
    return 0;
}
/*
6
S R R R S R
3 1 4 1 5 9
2 6 5 3 5
*/
/*
S R R R S R
3 1 4 1 5 9
0 2 6 5 3 5
*/
/*
0 0  0 2 7  7
0 -2 2 4 -1 -6
*/
