#include <iostream>
#include <vector>

using namespace std;

int N,K;
signed main(){
    vector<int>dat;
    while(cin>>N>>K){
        dat.assign(N,0);
        for(int i=0;i<N;++i){
            cin>>dat[i];
        }

        int las=dat[0],cur;
        int res=0;
        for(int i=1;i<N;++i){
            cur=dat[i];

            if(las<K && K<cur){
                ++res;
            }else if(las>K && K>cur){
                ++res;
            }else if(las==K){
                ++res;
            }

            las=cur;
        }
        if(las==K){++res;}
        cout<<res<<'\n';
    }
	return 0;
}
