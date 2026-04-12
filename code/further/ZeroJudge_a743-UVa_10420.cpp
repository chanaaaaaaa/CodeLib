#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    vector<string>dat;
    int N;
    cin>>N;
    while(N--){
        string A;
        cin>>A;
        dat.push_back(A);
        getline(cin,A);
    }
    sort(dat.begin(),dat.end());
    int same=1;
    for(int i=0;i<dat.size()-1;i++){
        if(same==1){
            cout<<dat[i]<<" ";
        }
        if(dat[i]==dat[i+1]){
            same++;
            if(i==dat.size()-2){
                cout<<same<<"\n";
            }
        }else{
            if(i==dat.size()-2 && same==1){
                cout<<"1"<<"\n"<<dat[i+1]<<" "<<"1"<<"\n";
            }else{
                cout<<same<<"\n";
            }
            same=1;
        }

    }
    return 0;
}
