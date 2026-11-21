#include <iostream>
#include <string>

using namespace std;

signed main(){
    int T,N;
    while(cin>>T){
        while(T--){
            cin>>N;
            int cnt=0;
            bool red=true;
            char c;
            for(int i=0;i<N;++i){
                cin>>c;
                if(red){
                    if(c=='R'){
                        red=false;
                    }else{
                        ++cnt;
                    }
                }else{
                    if(c=='B'){
                        red=true;
                    }else{
                        ++cnt;
                    }
                }
            }
            cout<<cnt<<'\n';
        }
    }
    return 0;
}
