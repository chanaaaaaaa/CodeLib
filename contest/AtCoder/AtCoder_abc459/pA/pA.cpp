#include <iostream>

using namespace std;

signed main(){
    int A;
    while(cin>>A){
        string S="HelloWorld";
        for(int i=1;i<=10;++i){
            if(i==A){continue;}
            cout<<S[i-1];
        }
        cout<<'\n';
    }
    return 0;
}
