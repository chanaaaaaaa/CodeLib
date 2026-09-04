#include <iostream>
#include <string>

using namespace std;

signed main(){
    int N;
    while(cin>>N){
        int A,B,res=0;
        string S;
        while(N--){
            cin>>A>>B>>S;
            if(S=="keep"){
                res+=B-A;
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}
