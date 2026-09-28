#include <iostream>

using namespace std;

signed main(){
    string S;
	while(cin>>S){
        if(S[S.size()-1]=='e'){
            cout<<S<<"r\n";
        }else{
            cout<<S<<"er\n";
        }
	}
	return 0;
}
