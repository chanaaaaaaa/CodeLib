#include <iostream>

using namespace std;

signed main(){
	int A,B,C;
	while(cin>>A>>B>>C){
		bool f=false;
		for(int i=A;i!=B;i=(i+1)%24){
			if(i==C){
				f=true;
			}
		}
		
		if(!f){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}
	return 0;
}