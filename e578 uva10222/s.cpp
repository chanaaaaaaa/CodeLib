#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int in[41]={92,93,91,112,111,105,117,121,116,114,101,39,59,108,107,106,104,103,102,100,47,46,44,109,110,98,118,63,61,45,48,57,56,55,54,53,52,51,50,99};
int ou[41]={91,112,111,105,117,121,116,114,101,119,113,108,107,106,104,103,102,100,115,97,44,109,110,98,118,99,120,122,48,57,56,55,54,53,52,51,50,49,96,122};

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string A;
    while(getline(cin,A)){
        for(int i=0;i<A.size();i++){
            if(int(A[i])==32){
                cout<<char(32);
                continue;
            }
            int pos=0;
            for(;pos<41;pos++){
                if(int(A[i])==in[pos]){
                    cout<<char(ou[pos]);
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
