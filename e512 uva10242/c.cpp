#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    double a[4][2];
    set<int>check;
    while(cin>>a[0][0]>>a[0][1]){
        for(int i=1;i<4;i++){
            cin>>a[i][0]>>a[i][1];
            for(int j=0;j<i;j++){
                if(check.empty()){
                    if(a[j][0]==a[i][0] && a[j][1]==a[i][1]){
                        check.insert(i);
                        check.insert(j);
                    }
                }
            }
        }
        double x=0,y=0;
        for(int i=0;i<4;i++){
            if(check.count(i)){
                x-=a[i][0]/2;
                y-=a[i][1]/2;
            }else{
                x+=a[i][0];
                y+=a[i][1];
            }
        }
        cout<<fixed<<setprecision(3)<<x<<" "<<y<<"\n";
        check.clear();
    }
    return 0;
}
