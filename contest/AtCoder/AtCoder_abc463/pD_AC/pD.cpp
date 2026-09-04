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
int N,K;
vector<pair<int,int>>cloths;

inline int BSA(){
    int Ls=0,Rs=1e9;

    while(Ls<Rs){
        int mid=(Ls+Rs)>>1;
        int res=0,las=0;

        for(const pair<int,int>it:cloths){
            if(las<=it.second){
                ++res;
                las=it.first+mid+1;
            }
        }

        if(res>=K){
            Ls=mid+1;
        }else{
            Rs=mid;
        }
    }
    return Ls;
}
signed main(){
    while(N=read()){
        K=read();
        cloths.assign(N,pair<int,int>());
        for(int i=0;i<N;++i){
            cloths[i].second=read();
            cloths[i].first=read();
        }
        sort(cloths.begin(),cloths.end());

        int ans=BSA();
        if(ans>0){
            write(ans);
        }else{
            putchar('-');
            putchar('1');
        }
        putchar('\n');
    }
    return 0;
}
/*
6 3
1 12
2 7*
5 9
9 13*
10 18
15 20*
*/
//0
//=....=....=....=....=
//012223322233211222110
