#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        if(i>1){cout<<"\n";}
        cout<<"Case "<<i<<":\n";

        int dat[36];
        for(int j=0;j<36;j++){
            cin>>dat[j];
        }

        int time;
        cin>>time;
        while(time--){
            map<int,int>Ans;
            int num,maxx=0x7FFFFFFF;
            cin>>num;
            cout<<"Cheapest base(s) for number "<<num<<":";
            for(int j=2;j<=36;j++){
                int x=num;
                while(x){
                    Ans[j]+=dat[x%j];
                    x/=j;
                }
                maxx=min(maxx,Ans[j]);
            }
            for(int j=2;j<=36;j++){
                if(Ans[j]==maxx){
                    cout<<" "<<j;
                }
            }
            cout<<"\n";
        }
    }

    return 0;
}
