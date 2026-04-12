#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin>>n;
    while(n--){
        int A,F;
        cin>>A>>F;
        while(F--){
            for(int i=1;i<=A;i++){
                int temp=i;
                while(temp--){cout<<i;}
                cout<<"\n";
            }
            for(int i=A-1;i>0;i--){
                int temp=i;
                while(temp--){cout<<i;}
                cout<<"\n";
            }
            cout<<"\n";
        }
    }
    return 0;
}
