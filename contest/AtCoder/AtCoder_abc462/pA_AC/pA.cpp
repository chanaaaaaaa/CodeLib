#include <iostream>

using namespace std;

signed main(){
    string S;
    while(cin>>S){
        for(char A:S){
            if(A>='0' && A<='9'){
                cout<<A;
            }
        }
        cout<<'\n';
    }
    return 0;
}
