#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <iostream>
#include <string>
using namespace std;

int co[96];
string A;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);


    while(getline(cin,A)){

        for(int i=0;i<A.size();i++){
            co[int(A[i])-32]++;
        }
        for(int i=1;i<A.size();i++){
            for(int j=95;j>=0;j--){
                if(co[j]==i){
                    cout<<j+32<<" "<<co[j]<<"\n";
                    co[j]=0;
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
