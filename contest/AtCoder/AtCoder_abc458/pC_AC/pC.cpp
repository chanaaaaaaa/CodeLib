#include <iostream>
#include <string>
#include <cmath>


#define int long long
using namespace std;

signed main(){
    string S;
    int minn,sz;
    while(cin>>S){
        minn=0;sz=S.size();
        for(int i=0;i<sz;++i){
            if(S[i]=='C'){
                minn+=min(i+1,sz-i);
            }
        }
        cout<<minn<<'\n';
    }
    return 0;
}
