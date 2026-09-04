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
int N,M,cnt;
vector<pair<int,pair<int,int>>>dat;//{day,{col1,col2}}
vector<int>cur;
signed main(){
    while(N=read()){
        M=read();
        dat.assign(N,pair<int,pair<int,int>>());
        cur.assign(N,0);
        for(int i=0;i<N;++i){
            dat[i].second.first=read()-1;
            dat[i].first=read();
            dat[i].second.second=read()-1;
        }
        //pfx init
        for(int i=0;i<N;++i){
            ++cur[dat[i].second.first];
        }
        cnt=0;
        for(int i=0;i<N;++i){
            if(cur[i]!=0){++cnt;}
        }
        //solve
        sort(dat.begin(),dat.end());
        for(int i=1,pos=0;i<=M;++i){
            while(pos<N && dat[pos].first<=i){
                --cur[dat[pos].second.first];
                if(cur[dat[pos].second.first]==0){--cnt;}
                if(cur[dat[pos].second.second]==0){++cnt;}
                ++cur[dat[pos].second.second];
                ++pos;
            }
            write(cnt);
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
