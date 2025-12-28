#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<iostream>
#include<string>
#define int long long

using namespace std;

signed main(){
    string s;
    while(cin>>s){
        bool datingCEO=false,
             datingBoy=false,
             cheated  =false;

        for(int i=0;i<s.size();++i){
            if(s[i]=='O'){
                datingCEO=!datingCEO;
            }else if(s[i]=='X'){
                datingBoy=!datingBoy;
            }

            if(datingCEO && datingBoy){
                cheated=true;
                break;
            }
        }

        if(cheated){
            cout<<"Bad girl\n";
        }else{
            cout<<"Good end\n";
        }
    }
    return 0;
}
