#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const long long NEG=LLONG_MIN/4;
int N,K;
vector<long long>A,B;
vector<vector<long long>>dp,ndp;

signed main(){
    while(cin>>N>>K){
        A.assign(N,0);
        B.assign(N,0);
        for(int i=0;i<N;++i){
            cin>>A[i]>>B[i];
        }

        dp.assign(K+1,vector<long long>(2,NEG));
        dp[0][0]=0;

        for(int i=0;i<N;++i){
            ndp.assign(K+1,vector<long long>(2,NEG));
            for(int k=0;k<=K;++k){
                if(dp[k][0]!=NEG){
                    ndp[k][0]=max(ndp[k][0],dp[k][0]+A[i]);
                    if(k+1<=K){
                        ndp[k+1][1]=max(ndp[k+1][1],dp[k][0]+B[i]);
                    }
                }
                if(dp[k][1]!=NEG){
                    ndp[k][1]=max(ndp[k][1],dp[k][1]+B[i]);
                    ndp[k][0]=max(ndp[k][0],dp[k][1]+A[i]);
                }
            }
            dp.swap(ndp);
        }

        long long res=NEG;
        for(int k=0;k<=K;++k){
            res=max(res,max(dp[k][0],dp[k][1]));
        }
        cout<<res<<'\n';
    }
    return 0;
}
