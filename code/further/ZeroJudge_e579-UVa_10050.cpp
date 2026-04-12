#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin>>N;
    while(N--){
        int don[100];
        int day,party,Ans=0;
        cin>>day>>party;
        for(int i=0;i<party;i++){
            cin>>don[i];
        }
        for(int i=1;i<=day;i++){
            if(!(i%7==6 || i%7==0)){
                for(int j=0;j<party;j++){
                    if(i%don[j]==0){
                        Ans++;
                        break;
                    }
                }
            }
        }
        cout<<Ans<<"\n";
    }
    return 0;
}
