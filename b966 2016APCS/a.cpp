#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    bool check=true;
    while(cin>>N){
        if(check)check=false;
        else cout<<"\n";

        pair<int,int>dat[10005];
        for(int k=0;k<N;k++){
            cin>>dat[k].first>>dat[k].second;
        }
        sort(dat,dat+N);
        int head=-1,bottom=-1,Ans=0;
        for(int i=0;i<N;i++){
            if(bottom<dat[i].first) Ans+=bottom-head,head=dat[i].first,bottom=dat[i].second;
            else bottom=max(bottom,dat[i].second);
        }
        Ans+=bottom-head;
        cout<<Ans;
    }
    return 0;
}
