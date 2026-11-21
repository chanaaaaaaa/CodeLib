#include <iostream>
#include <string>
using namespace std;

signed main(){
    int N,M;
    char S[105][105];
    while(cin>>N>>M){
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                cin>>S[i][j];
            }
        }

        bool fd=false;
        for(int i=0;i<N && !fd;++i){
            bool tmp=true;
            for(int j=0;j<M && tmp;++j){
                if(S[i][j]=='o'){tmp=false;}
            }
            if(tmp){
                cout<<"Faucet "<<i+1<<'\n';
                fd=true;
            }
        }

        for(int j=0;j<M && !fd;++j){
            bool tmp=true;
            for(int i=0;i<N && tmp;++i){
                if(S[i][j]=='o'){tmp=false;}
            }
            if(tmp){
                cout<<"Drain "<<j+1<<'\n';
                fd=true;
            }
        }
    }
    return 0;
}
