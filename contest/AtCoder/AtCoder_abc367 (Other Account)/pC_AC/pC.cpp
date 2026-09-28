#include <iostream>
#include <vector>
using namespace std;

vector<int>dat;
int N,K;
	
inline void dfs(int dep,int sum,string s){
	if(dep==N && sum%K==0){
		cout<<s<<'\n';
	}
	for(int i=1;i<=dat[dep];++i){
		string tps=s+char(i+'0');
		dfs(dep+1,sum+i,tps+' ');
	}
	return;
}

signed main(){
	while(cin>>N>>K){
		dat.assign(N,0);
		for(int i=0;i<N;++i){
			cin>>dat[i];
		}
		dfs(0,0,"");
	}
	return 0;
}