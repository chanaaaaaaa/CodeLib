#include <iostream>
#include <string>

using namespace std;


signed main(){
	string S;
	while(cin>>S){
		int sz=S.size()-1;
		while(S[sz]=='0'){
			--sz;
		}
		
		if(S[sz]=='.'){--sz;}
		
		for(int i=0;i<=sz;++i){
			cout<<S[i];
		}
		cout<<'\n';
	}
	return 0;
}