#include <iostream>
#include <vector>

using namespace std;


vector<int>dat;
vector<int>res;
int N,M;
signed main(){
    while(cin>>N>>M){
        dat.assign(N,0);
        res.clear();
        for(int i=0;i<N;++i){
            cin>>dat[i];
        }

        for(int i=0;i<N;++i){
            bool f=true;
            for(int j=0;j<N && f;++j){
                if(i==j){continue;}
                if(abs(dat[i]-dat[j])<M){f=false;}
            }
            if(f){res.push_back(i+1);}
        }

        cout<<res.size()<<'\n';
        for(int r:res){
            cout<<r<<' ';
        }
        cout<<'\n';
    }
	return 0;
}
