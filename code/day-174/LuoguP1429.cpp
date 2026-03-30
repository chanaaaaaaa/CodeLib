#include <cstdio>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#include <math.h>

#define int long long
using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}

vector<pair<int,int>>dat;
set<pair<int,int>>slides;
int N,posL,posR;

inline void solve(){
    sort(dat.begin(),dat.end());

    int dis=9e18;

    for(posL=0,posR=0;posR<N;++posR){
        while((dat[posL].first-dat[posR].first)*(dat[posL].first-dat[posR].first) > dis){
            slides.erase({dat[posL].second,posL});
            ++posL;
        }

        double d=sqrt(dis);
        set<pair<int,int>>::iterator posit=slides.lower_bound({dat[posR].second-d,0});
        while(posit!=slides.end() && posit->first < dat[posR].second+dis){
            dis=min(dis,(dat[posit->second].first-dat[posR].first)*(dat[posit->second].first-dat[posR].first)+(dat[posit->second].second-dat[posR].second)*(dat[posit->second].second-dat[posR].second));
            ++posit;
        }

        slides.insert({dat[posR].second,posR});
    }
    printf("%.4f\n",sqrt(dis));
    return;
}

signed main(){
    while(N=read()){
        dat.clear();
        slides.clear();
        dat.assign(N,pair<int,int>());
        for(int i=0;i<N;++i){
            dat[i].first=read();
            dat[i].second=read();
        }
        solve();
    }
    return 0;
}
