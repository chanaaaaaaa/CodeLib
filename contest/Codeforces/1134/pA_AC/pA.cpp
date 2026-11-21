#include <iostream>
#include <algorithm>
using namespace std;

signed main(){
    int T,a[3];
    while(cin>>T){
        while(T--){
            cin>>a[0]>>a[1]>>a[2];
            sort(a,a+3);
            if(a[0]+1==a[1] && a[1]+1==a[2]){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
    return 0;
}
