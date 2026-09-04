#include <iostream>

using namespace std;


signed main(){
    int L;
    string S;
    char A;
    bool f;
    while(cin>>L>>A){
        f=false;
        while(L--){
            cin>>S;
            if(S[A-'A']=='o'){
                f=true;
            }
        }

        if(f){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}
