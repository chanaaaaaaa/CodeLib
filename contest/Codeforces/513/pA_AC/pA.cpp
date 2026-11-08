#include <iostream>
#include <string>
using namespace std;

signed main(){
    int N,cnt;
    char C;
    while(cin>>N){
        cnt=0;
        for(int i=0;i<N;++i){
            cin>>C;
            if(C=='8'){++cnt;}
        }
        cout<<min(cnt,N/11)<<'\n';
    }
    return 0;
}
