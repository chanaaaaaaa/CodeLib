#include <cstdio>

using namespace std;

inline int read(){
    int x=0,c=0,w=1;
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
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}
//-
const int MAXN=1e5+10;
struct nds{
    int Ls,Rs;
    long long val;
}segt[MAXN<<2];
int dat[MAXN];
int N,Q;

inline void build(int node,int L,int R){
    segt[node].Ls=L;
    segt[node].Rs=R;
    if(L==R){
        segt[node].val=dat[L];
        return;
    }

    int mid=(L+R)>>1;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    segt[node].val=segt[node*2].val+segt[node*2+1].val;
    return;
}
inline void update(int node,int p,int val){
    
}
inline int query(int node,int L,int R,int val){

}

signed main(){
    while(N=read()){
        Q=read();
        for(int i=1;i<=N;++i){
            dat[i]=read();
        }
        build(1,1,N);
        while(Q--){
            int c,x,l,r,k;
            c=read();
            x=read();
            l=read();
            r=read();
            k=read();
            update(1,c,x);
            query(1,l,r,k);
        }
    }
    return 0;
}