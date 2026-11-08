#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>dat;
int N,Q,op;
signed main(){
    while(cin>>N>>Q){
        dat.assign(N,0);
        for(int i=0;i<N;++i){
            dat[i]=i+1;
        }
        for(int i=0;i<Q;++i){
            cin>>op;
            for(int j=0;j<op;++j){
                dat[j]=-dat[j];
            }
            reverse(dat.begin(),dat.begin()+op);
        }

        for(int i=0;i<N;++i){
            cout<<dat[i]<<'\n';
        }
    }
	return 0;
}
