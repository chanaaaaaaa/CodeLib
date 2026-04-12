#include <bits/stdc++.h>
using namespace std;

inline bool check(string A,string B){
    string AA="",BB="";
    for(int i=0;i<A.size();i++){if(A[i]!=' '){AA+=A[i];}}
    for(int i=0;i<B.size();i++){if(B[i]!=' '){BB+=B[i];}}

    return AA==BB;
}

int main(){
    int N;
    cin>>N;
    cin.ignore();
    for(int i=1;i<=N;i++){
        string team,judge;
        getline(cin,team);
        getline(cin,judge);

        if(team==judge){cout<<"Case "<<i<<": Yes\n";}
        else if(check(team,judge)){cout<<"Case "<<i<<": Output Format Error\n";}
        else{cout<<"Case "<<i<<": Wrong Answer\n";}
    }
    return 0;
}
