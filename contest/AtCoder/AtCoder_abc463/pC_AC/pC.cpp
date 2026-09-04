#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

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
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}
//
inline bool cmp(const pair<int,pair<int,int>>&a,const pair<int,pair<int,int>>&b){
    return a.second.first<b.second.first;
}


int N,Q;
vector<pair<int,int>>dat;
vector<pair<int,pair<int,int>>>query;
signed main(){
    while(N=read()){
        dat.assign(N,pair<int,int>());
        for(int i=0;i<N;++i){
            dat[i].second=read();
            dat[i].first=read();
        }
        sort(dat.begin(),dat.end());

        Q=read();
        query.assign(Q,pair<int,pair<int,int>>());
        for(int i=0;i<Q;++i){
            query[i].first=read();
            query[i].second.first=i;
            query[i].second.second=0;
        }
        sort(query.begin(),query.end());

        int maxx=0,pos=N-1;
        for(int i=query.size()-1;i>=0;--i){
            while(dat[pos].first>query[i].first){
                maxx=max(maxx,dat[pos].second);
                if(pos==0){break;}
                --pos;
            }
            query[i].second.second=maxx;
        }
        sort(query.begin(),query.end(),cmp);

        for(int i=0;i<query.size();++i){
            write(query[i].second.second);
            putchar('\n');
        }
    }
    return 0;
}
