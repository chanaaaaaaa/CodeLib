#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>

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
signed main(){
    vector<pair<int,int>>dat;
    unordered_set<int>mp;
    int N,M,K;
    while(N=read()){
        M=read();K=read();
        dat.assign(N,pair<int,int>());
        mp.clear();
        for(int i=0;i<N;++i){
            dat[i].second=read();
            dat[i].first=read();
        }
        sort(dat.begin(),dat.end());
        reverse(dat.begin(),dat.end());
        int res=0;
        for(int i=0;i<N;++i){
            if(M==0){break;}
            if(M+mp.size()==K){
                if(!mp.count(dat[i].second)){
                    --M;
                    res+=dat[i].first;
                    mp.insert(dat[i].second);
                }
            }else{
                --M;
                res+=dat[i].first;
                mp.insert(dat[i].second);
            }
        }
        write(res);
        putchar('\n');
    }
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
