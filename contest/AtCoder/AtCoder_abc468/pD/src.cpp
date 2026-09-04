#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <string>

using namespace std;

string S;
inline bool isgood(int L,int R){
    int chance=0;
    while(L<R){
        if(S[L]!=S[R]){
            ++chance;
            if(chance==2){
                return false;
            }
        }
        ++L;
        --R;
    }
    return true;
}


signed main(){
    while(cin>>S){
        int res=S.size()*3-3;
        for(int i=0;i<S.size();++i){
            for(int j=3;j+i<S.size();++j){
                if(isgood(i,i+j)){
                    ++res;
                }
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}
