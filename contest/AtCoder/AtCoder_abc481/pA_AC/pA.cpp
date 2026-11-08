#include <iostream>

using namespace std;

signed main(){
    int N,M;
    while(cin>>N>>M){
        N+=M;
        M=0;
        while(N){
            N/=10;
            ++M;
        }
        cout<<M<<'\n';
    }
	return 0;
}
