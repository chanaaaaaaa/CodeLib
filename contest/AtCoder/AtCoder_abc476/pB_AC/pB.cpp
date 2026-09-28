#include <iostream>

using namespace std;

int N;
string A,B;
signed main(){
    while(cin>>N>>A>>B){
        bool f=true;
        for(int i=0;i<N && f;++i){
            if(B[i]=='*'){continue;}
            if(A[i]!=B[i]){f=false;}
        }
        if(f){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
	return 0;
}
