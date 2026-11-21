#include <iostream>
#include <set>
using namespace std;

set<int>dat;
int N,tmp;
signed main(){
    while(cin>>N){
        dat.clear();
        for(int i=0;i<N;++i){
            cin>>tmp;
            dat.insert(tmp);
        }
        if(dat.count(9)){
            cout<<*dat.begin()<<'\n';
        }else{
            cout<<"-1\n";
        }
    }
	return 0;
}
