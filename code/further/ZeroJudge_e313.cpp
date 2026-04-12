#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,nah,AnsN=27;
    string IN,AnsS,d;

    cin>>N;
    while(N--){
        nah=1;
        cin>>IN;
        d=IN;
        sort(d.begin(),d.end());
        for(int i=1;i<d.size();i++){
            if(d[i]!=d[i-1])nah++;
        }
        if((nah<AnsN)||((nah==AnsN)&&(IN<AnsS))){AnsN=nah;AnsS=IN;}
    }
    cout<<AnsS<<"\n";
    return 0;
}
