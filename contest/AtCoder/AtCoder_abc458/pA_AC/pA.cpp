#include <iostream>

using namespace std;

signed main(){
    int N;
    string S;
    while(cin>>S>>N){
        for(int i=N;i<S.size()-N;++i){
            cout<<S[i];
        }
        cout<<'\n';
    }
    return 0;
}
