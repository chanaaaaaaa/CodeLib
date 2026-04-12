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
        cout<<"Test #"<<i<<": ";

        vector<long long>dat;
        int n;
        cin.ignore();
        cin.ignore();
        cin.ignore();
        cin.ignore();
        cin>>n;

        int maxx=n*n;
        for(int j=0;j<maxx;j++){
            long long temp;
            cin>>temp;
            dat.push_back(temp);
        }
        if(n==1){
            if(dat[0]>=0){cout<<"Symmetric.\n";}
            else{cout<<"Non-symmetric.\n";}
            continue;
        }
        int flag=0;
        for(int j=0;j<maxx;j++){
            if(dat[j]!=dat[maxx-1-j] || dat[j]<0 || dat[maxx-1-j]<0){
                flag=1;
                break;
            }
        }
        if(flag==1){cout<<"Non-symmetric.\n";}
        else{cout<<"Symmetric.\n";}
    }
    return 0;
}
