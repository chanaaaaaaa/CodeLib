#include <cstdio>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>

#define int long long
using namespace std;

inline int read(){
    int x=0,w=1,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
vector<pair<int,int>>cows;
vector<pair<int,int>>fark;
set<pair<int,int>>slides;
int N,C,x,y,posL,posR,res_cnt,res_max;

inline int findf(int x){
    if(fark[x].first==x){return x;}
    return fark[x].first=findf(fark[x].first);
}
inline void unite(int a,int b){
    a=findf(a);
    b=findf(b);
    if(a==b){return;}

    --res_cnt;

    if(fark[a].second > fark[b].second){
        fark[a].second+=fark[b].second;
        fark[b].first=a;
        res_max=max(res_max,fark[a].second);
    }else{
        fark[b].second+=fark[a].second;
        fark[a].first=b;
        res_max=max(res_max,fark[b].second);
    }
    return;
}

inline void solve(){
    sort(cows.begin(),cows.end());

    for(posR=0,posL=0,res_cnt=N,res_max=1;posR<N;++posR){
        while(cows[posR].first - cows[posL].first > C){
            slides.erase({cows[posL].second,posL});
            ++posL;
        }

        set<pair<int,int>>::iterator pos=slides.lower_bound({cows[posR].second-C,0});
        if(pos!=slides.end() && pos->first <= cows[posR].second+C){
            unite(pos->second,posR);

            pos=slides.upper_bound({cows[posR].second+C,N+1});
            --pos;
            unite(pos->second,posR);
        }

        slides.insert({cows[posR].second,posR});
    }
    return;
}

signed main(){
    while(N=read()){
        C=read();
        cows.clear();
        fark.clear();
        slides.clear();

        for(int i=0;i<N;++i){
            x=read();y=read();
            fark.push_back({i,1});
            cows.push_back({x+y,x-y});
        }
        solve();
        write(res_cnt);
        putchar(' ');
        write(res_max);
        putchar('\n');
    }
    return 0;
}
