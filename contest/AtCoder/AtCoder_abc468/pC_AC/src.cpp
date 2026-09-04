#include <bits/stdc++.h>

using namespace std;

signed main(){
    int N;
    while(cin>>N){
        vector<int>dat(N);
        vector<int>lim(N);
        vector<int>tar(N);
        int cnt=0;
        for(int i=0;i<N;++i){cin>>dat[i];}
        for(int i=0;i<N;++i){cin>>tar[i];}
        lim.assign(dat.begin(),dat.end());
        sort(lim.begin(),lim.end());

        if(dat==tar){
            cout<<0<<'\n';
            continue;
        }
        while(dat!=tar){
            ++cnt;
            next_permutation(dat.begin(),dat.end());
            if(dat==lim){cnt=1;break;}
        }

        cout<<cnt-1<<'\n';
    }
    return 0;
}
