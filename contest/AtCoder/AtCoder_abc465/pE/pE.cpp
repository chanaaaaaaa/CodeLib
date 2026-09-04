#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
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
//===
const int MAXN=3e5+50;
struct nds{
    int Ls,Rs,name_up,name_le,val;
}segt[MAXN<<2];
vector<pair<int,int>>dat;
int N,Q,A,B;

inline void build(int node,int L,int R){
    segt[node].Ls=L;
    segt[node].Rs=R;
    if(L==R){
        segt[node].name_up=segt[node].name_le=dat[L].first;
        segt[node].val=dat[L].second;
        return;
    }
    int mid=(L+R)>>1;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);

    segt[node].val=segt[node*2].val+segt[node*2+1].val;
    segt[node].name_le=segt[node*2].name_le;
    segt[node].name_up=segt[node*2+1].name_up;
    return;
}
inline int query(int node,int L,int R){
    if(L>segt[node].name_up || R<segt[node].name_le){
        return 0;
    }
    if(L<=segt[node].name_le && segt[node].name_up<=R){
        write(segt[node].name_le);
        putchar(' ');
        write(segt[node].name_up);
        putchar('\n');
        //
        return segt[node].val;
    }
    return query(node*2,L,R)+query(node*2+1,L,R);
}


signed main(){
    while(N=read()){
        dat.assign(N+1,pair<int,int>());
        dat[0]={-1,-1};
        for(int i=1;i<=N;++i){
            dat[i].first=read();
            dat[i].second=read();
        }
        sort(dat.begin(),dat.end());
        //
        for(int i=0;i<=N;++i){
            write(dat[i].first);
            putchar(' ');
            write(dat[i].second);
            putchar('\n');
        }
        putchar('\n');
        //
        build(1,1,N);
        Q=read();
        while(Q--){
            A=read();B=read();
            if(A>B){swap(A,B);}
            write(query(1,A,B));
            putchar('\n');
        }
    }
    return 0;
}
