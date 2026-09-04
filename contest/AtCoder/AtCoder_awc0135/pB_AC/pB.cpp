#include <iostream>

using namespace std;

int N;
signed main(){
    while(cin>>N){
        double a,b,minn=1000000,min_id=-1;
        for(int i=1;i<=N;++i){
            cin>>a>>b;
            //cout<<a/b;
            if(a/b<minn){
                minn=a/b;
                min_id=i;
            }
        }
        cout<<min_id<<'\n';
    }
    return 0;
}
