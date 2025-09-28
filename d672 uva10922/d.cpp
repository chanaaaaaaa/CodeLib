#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string A;
    while(cin>>A){
        if(A=="0"){break;}

        stringstream doi(A);
        char temp;
        int first=0,deg=1;
        while(doi>>temp){
            first+=int(temp)-48;
        }
        if(first%9!=0){
            cout<<A<<" is not a multiple of 9."<<"\n";
            continue;
        }
        while(first>9){
            deg++;
            int next=0,now=0;
            while(first>0){
                int cal=first/pow(10,now);
                next+=cal%10;
                first-=(cal%10)*pow(10,now);
                now++;
            }
            first=next;
        }
        cout<<A<<" is a multiple of 9 and has 9-degree "<<deg<<"."<<"\n";
    }
    return 0;
}
