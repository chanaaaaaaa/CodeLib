#include <iostream>

using namespace std;

signed main(){
    int A,B;
    while(cin>>A>>B){
        if(A*3>B*2){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}
