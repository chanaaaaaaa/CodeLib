#include <iostream>

using namespace std;

int N,Ls,Rs,res;
string S;

signed main(){
    while(cin>>N){
        res=0;
        Ls=1;
        for(Rs=2;Rs<=N;++Rs){
            cout<<"? "<<Ls<<' '<<Rs<<endl;
            cin>>S;
            if(S=="Yes"){
                res+=Rs-Ls;
            }else{
                if(Ls+1<Rs){--Rs;}
                ++Ls;
            }
        }
        cout<<"! "<<res<<endl;
    }
    return 0;
}
