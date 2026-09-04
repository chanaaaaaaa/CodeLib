#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N,K;
string S;
vector<int> dat;
vector<double> pref;

inline bool check(double p){
    pref[0]=0.0;
    for(int i=0;i<N;++i){
        pref[i+1]=pref[i]+((S[i]=='o')?(1.0-p):(-p));
    }

    double mn=1e300;
    int j=0;
    for(int r=1;r<=N;++r){
        while(j<r && dat[r]-dat[j]>=K){
            mn=min(mn,pref[j]);
            ++j;
        }
        if(j>0 && mn<=pref[r]) return true;
    }
    return false;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin>>N>>K>>S){
        dat.assign(N+1,0);
        pref.assign(N+1,0.0);

        for(int i=0;i<N;++i){
            dat[i+1]=dat[i]+(S[i]=='o'?1:0);
        }

        double Ls=0.0,Rs=1.0,mid;
        for(int i=0;i<80;++i){
            mid=Ls+(Rs-Ls)/2.0;
            if(check(mid)) Ls=mid;
            else Rs=mid;
        }

        printf("%.10f\n",Ls);
    }
    return 0;
}
