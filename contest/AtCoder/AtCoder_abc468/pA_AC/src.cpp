#include <iostream>

using namespace std;

int dat[150];
int N;
signed main(){
    while(cin>>N){
        for(int i=0;i<N;++i){
            cin>>dat[i];
        }
        int cnt=0;
        for(int i=1;i<N-1;++i){
            if(dat[i-1]<dat[i] && dat[i]>dat[i+1]){
                ++cnt;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
