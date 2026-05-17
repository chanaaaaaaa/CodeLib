#include <iostream>
#include <string>

using namespace std;

signed main(){
    string S;
    getline(cin,S);

    bool f=true;
    for(int i=0;f && i<S.size()/2;++i){
        if(S[i]!=S[S.size()-i-1]){
            f=false;
        }
    }

    int lim=(S.size()-1)/2;
    for(int i=0;f && i<lim;++i){
        if(S[i]!=S[lim-i-1]){
            f=false;
        }
    }

    lim=S.size();
    for(int i=(S.size()-1)/2;f && i<lim;++i){
        if(S[i]!=S[lim-i-1]){
            f=false;
        }
    }

    if(f){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    return 0;
}
