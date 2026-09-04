#include <iostream>

using namespace std;

signed main(){
    int A,B;
    while(cin>>A>>B){
        if(B*16==A*9){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}
