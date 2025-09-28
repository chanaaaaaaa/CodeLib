#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x,jud=0;
    for(int i=0;i<2;i++){
        int p[2]={0,0};
        for(int j=0;j<2;j++){
            for(int g=0;g<4;g++){
                cin>>x;
                p[j]+=x;
            }
        }
        if(p[0]>p[1])jud++;
        else if(p[0]<p[1])jud--;
        cout<<p[0]<<":"<<p[1]<<"\n";
    }
    if(jud==-2)cout<<"Lose\n";
    else if(jud==2)cout<<"Win\n";
    else cout<<"Tie\n";
    return 0;
}
