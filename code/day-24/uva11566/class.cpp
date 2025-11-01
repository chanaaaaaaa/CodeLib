#include <iostream>
#include <vector>
#include <memory.h>
#include <iomanip>

using namespace std;

int main(){
	// fast io
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, x, T, K;
	int P;
	int dp[23][1001];

	while(cin>>N>>x>>T>>K,N+x+T+K){
		P=(++N*x)/(float)1.1-(N*T);

		vector<pair<int,int>>pf;
		memset(dp,0,sizeof(dp));
		int ans=0;

		for(int i=0;i<K;++i){
			int a,b=0,tmp;

			cin>>a;
			for(int j=0;j<N;++j)cin>>tmp,b+=tmp;

			pf.push_back({a,b});
			pf.push_back({a,b});
		}

		for (int k = 0; k < pf.size(); ++k){
			auto& [price,favour]=pf[k];
			for(int i=N*2;i>0;--i) for(int j=P;j>=price;--j)
				dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i-1][j-price]+favour));
		}

		for(int i=0;i<=N*2;++i)ans=max(ans,dp[i][P]);
		cout<<setprecision(2)<<fixed<<(double)ans/N<<"\n";
	}

	return 0;
}
