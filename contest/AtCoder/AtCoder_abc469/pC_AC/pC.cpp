#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

signed main(){
    int N;
    string S;
    while(cin>>N>>S){
        vector<int>dat(S.size(),0);
        if(S[0]=='x'){
            dat[0]=1;
        }
        for(int i=1;i<N;++i){
            if(S[i]=='x'){
                dat[i]=dat[i-1]+1;
            }else{
                dat[i]=dat[i-1];
            }
        }
        //for(int i=0;i<N;++i){cout<<dat[i]<<' ';}
        //cout<<'\n';
        for(int i=1;i<=N;++i){
            int res=lower_bound(dat.begin(),dat.end(),i)-dat.begin();

            if(res==N){
                cout<<res<<'\n';
            }else{
                cout<<res+1<<'\n';
            }
        }
    }
    return 0;
}
