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
signed main(){

    int N=read();
    vector<pair<int,int>>dat(N);
    for(int i=0;i<N;++i){
        dat[i].first=read()-1;
        dat[i].second=read()-1;
    }
    sort(dat.begin(),dat.end());

    int minn=N;
    int res=0;
    for(auto &[x,y]:dat){
        minn=min(minn,y);
        res+=minn==y;
    }
    write(res);
    putchar('\n');
    return 0;
}
/*

xxxxxo
xxxoxx
xxoxxx
xxxxox
xoxxxx
xxxxxx

*/
