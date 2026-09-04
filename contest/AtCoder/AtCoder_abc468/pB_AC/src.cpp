#include <iostream>
#include <string>

using namespace std;

signed main(){
    int M,D;
    string S;
    while(cin>>M>>D>>S){
        int res=0,pin=-1;
        while(pin<M){
            ++pin;
            if(pin==M){break;}
            if(S[pin]=='G'){continue;}
            bool flag=true;
            for(int i=1;i<=D && pin-i>=0 && flag;++i){
                if(S[pin-i]=='G'){
                    flag=false;
                }
            }
            for(int i=1;i<=D && pin+i<M && flag;++i){
                if(S[pin+i]=='G'){
                    flag=false;
                }
            }
            if(flag){++res;}
        }
        cout<<res<<'\n';
    }
    return 0;
}
