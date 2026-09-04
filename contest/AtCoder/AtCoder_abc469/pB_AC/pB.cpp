#include <iostream>
#include <string>
using namespace std;

signed main(){
    int N,res;
    string S;
    while(cin>>N>>S){
        res=0;
        if(N==1){
            if(S[0]=='x'){
                cout<<"1\n";
            }else{
                cout<<"0\n";
            }
            continue;
        }

        for(int i=0;i<N;++i){
            if(i==0){
                if(S[i]=='x'&&S[i+1]=='x'){
                    ++res;
                    //++i;
                }
            }else if(i==N-1){
                if(S[i]=='x'&&S[i-1]=='x'){
                    ++res;
                    //++i;
                }
            }else{
                if(S[i]=='x'&&S[i-1]=='x'&&S[i+1]=='x'){
                    ++res;
                    //++i;
                }
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}
