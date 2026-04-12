#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int dic[26];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N,maxx=0;
    cin>>N;
    cin.ignore();
    while(N--){
        string A;
        getline(cin,A);
        for(int i=0;i<A.size();i++){
            int temp=int(A[i]);
            if(temp>=65 && temp<=90){
               dic[temp-65]++;
               if(dic[temp-65]>maxx) maxx=dic[temp-65];
            }else if(temp>=97 && temp<=122){
                dic[temp-97]++;
                if(dic[temp-97]>maxx) maxx=dic[temp-97];
            }
        }
    }
    for(int i=maxx;i>0;i--){
        for(int j=0;j<26;j++){
            if(dic[j]==i){
                cout<<char(j+65)<<" "<<i<<"\n";
            }
        }
    }
    return 0;
}
