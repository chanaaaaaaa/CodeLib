#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string IN;
    int Ans;
    cin>>IN;
    for(int i=0;i<IN.size();i++){
        if((i&1)==0)Ans+=IN[i]-48;
        else Ans-=IN[i]-48;
    }
    cout<<abs(Ans)<<"\n";
    return 0;
}
