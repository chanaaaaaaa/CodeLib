#include <iostream>
#include <string>

using namespace std;

signed main(){
    int N,M;
    while(cin>>N>>M){
        int res=0;
        while(M){
            M=N%M;
            ++res;
        }
        cout<<res<<'\n';
    }
    return 0;
}
