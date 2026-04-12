#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int x;
    while(cin>>x){
        string sp,in;
        getline(cin,sp);
        getline(cin,in);
        stringstream read(in);

        int temp;
        long long Ans=0;
        vector<int>f;
        while(read>>temp){
            f.push_back(temp);
        }
        for(int i=0;i<f.size()-1;i++){
            Ans*=x;
            Ans+=f[i]*(f.size()-1-i);
        }
        cout<<Ans<<"\n";

    }
    return 0;
}
