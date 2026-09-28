#include <iostream>
#include <vector>
#include <utility>
#include <climits>
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
}
//block
inline pair<int,int> minp(const pair<int,int>&a,const pair<int,int>&b){
    return a.first<b.first?a:b;
}
inline pair<int,int> maxp(const pair<int,int>&a,const pair<int,int>&b){
    return a.first>b.first?a:b;
}

const int MAXN=2e5+5;

struct nds{
    int Ls,Rs;
    pair<int,int>np;
}segt[2][MAXN<<2];

pair<int,int>dat[MAXN];

int N,M,l,r;
//type 0:min,1:max
inline void build(int node, int L, int R,int type){
    segt[type][node].Ls=L;
    segt[type][node].Rs=R;
    if(L==R){
        segt[type][node].np=dat[L];
        return;
    }

    int mid=(L+R)>>1;
    build(node*2,L,mid,type);
    build(node*2+1,mid+1,R,type);

    if(type==0){
        segt[0][node].np=minp(segt[0][node*2].np,segt[0][node*2+1].np);
    }
    if(type==1){
        segt[1][node].np=maxp(segt[1][node*2].np,segt[1][node*2+1].np);
    }
    return;
}
inline pair<int,int> query(int node,int L,int R,int type){
    if(L<=segt[type][node].Ls && segt[type][node].Rs<=R){
        return segt[type][node].np;
    }
    if(R<segt[type][node].Ls || segt[type][node].Rs<L){
        if(type==0){
            return {INT_MAX,0};
        }
        if(type==1){
            return {0,0};
        }
    }

    if(type==0){
        return minp(query(node*2,L,R,type),query(node*2+1,L,R,type));
    }
    if(type==1){
        return maxp(query(node*2,L,R,type),query(node*2+1,L,R,type));
    }
}
inline void update(int node, int L, int R, int val,int type){
    if(R<segt[type][node].Ls || segt[type][node].Rs<L){
        return;
    }
    if(segt[type][node].Ls==L && segt[type][node].Rs==R){
        segt[type][node].np.first=val;
        return;
    }

    update(node*2,L,R,val,type);
    update(node*2+1,L,R,val,type);

    if(type==0){
        segt[0][node].np=minp(segt[0][node*2].np,segt[0][node*2+1].np);
    }
    if(type==1){
        segt[1][node].np=maxp(segt[1][node*2].np,segt[1][node*2+1].np);
    }
    return;
}
signed main(){
    while(N=read()){
        M=read();

        for(int i=1;i<=N;++i){
            dat[i]={read(),i};
        }

        build(1,1,N,0);
        build(1,1,N,1);
        for(int Q=1;Q<=M;++Q){
            l=read();r=read();

            pair<int,int>sml=query(1,l,r,0);
            pair<int,int>big=query(1,l,r,1);

            swap(dat[sml.second].first,dat[big.second].first);

            update(1,sml.second,sml.second,big.first,0);
            update(1,big.second,big.second,sml.first,0);

            update(1,sml.second,sml.second,big.first,1);
            update(1,big.second,big.second,sml.first,1);
        }

        for(int i=1;i<=N;++i){
            write(dat[i].first);
            putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
