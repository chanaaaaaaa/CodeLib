#include <set>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N,M;
set<pair<int,int>>st;
signed main(){
    while(cin>>N>>M){
        st.clear();
        for(int i=0;i<M;++i){
            int a,b;
            cin>>a>>b;
            st.insert({a,b});
            st.insert({b,a});
        }
        for()
    }
    return 0;
}
