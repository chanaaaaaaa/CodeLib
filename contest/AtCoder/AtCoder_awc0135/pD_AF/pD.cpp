#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

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
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}
//
int N,M;
vector<pair<int,int>>dat;

inline bool solve(int val){



}

signed main(){
    while(N=read()){
        dat.assign(N,pair<int,int>());
        for(int i=0;i<N;++i){
            dat[i].first=read();
            dat[i].second=read();
        }
        sort(dat.begin(),dat.end());
        int Ls=dat[0].first,Rs=dat[dat.size()-1].first;
        if(Rs-Ls>V*2-2){
            putchar('-');
            putchar('1');
            putchar('\n');
            continue;
        }

        while(Ls<=Rs){
            int mid=(Ls+Rs)>>1;
            if(solve(mid)){
                Rs=mid;
            }else{
                Ls=mid+1;
            }
        }
        write(Ls);
        putchar('\n');
    }
    return 0;
}
/*
8 10

0 15
2 80
5 21
8 100
11 70
13 42
16 18
18 55-
*/
//475 469 464 458 454 450 448 446 444 444 444 444 446 448 452 456 460 466 462
