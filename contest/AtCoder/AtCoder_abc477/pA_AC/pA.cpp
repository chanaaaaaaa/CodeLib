#include <iostream>

using namespace std;

signed main(){
    string S;
	while(cin>>S){
        if(S=="B"){
            cout<<"Y\n";
        }else if(S=="Y"){
            cout<<"R\n";
        }else{
            cout<<"B\n";
        }
	}
	return 0;
}
