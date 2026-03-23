#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<stdio.h>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

//-block
int T,t,n,sum;

signed main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&t,&n);
        vector<int>dp(20001,INT_MAX/2);
        vector<int>coin(n);
        dp[0]=0;
        for(int i=0;i<n;i++){
            scanf("%d",&coin[i]);
            if(sum<t){sum+=coin[i];}
        }

        for(int i=0;i<n;i++){
            for(int j=sum;j>=coin[i];j--){
                dp[j]=min(dp[j],dp[j-coin[i]]+1);
            }
        }
        while(dp[t]==INT_MAX/2){t++;}
        printf("%d %d\n",t,dp[t]);
    }
    return 0;
}
