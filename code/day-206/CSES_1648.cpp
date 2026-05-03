#include <cstdio>

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
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}
//-block
inline int min(int a,int b){
    return a<b?a:b;
}
#define FUNC(a,b) min(a.val,b.val)

const int MAXN=2e5+10;
const int MAX_RES=1e9+10;
struct nd{
    int L,R;
    long long val,lazy;
}segt[MAXN<<2];
int arr[MAXN]={0};

inline void build(int node,int L,int R){
    segt[node].L=L;
    segt[node].R=R;
    if(segt[node].L==segt[node].R){
        segt[node].val=arr[segt[node].L];
        segt[node].lazy=0;
        return;
    }

    int mid=(L+R)>>1;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);

    segt[node].val=FUNC(segt[node*2],segt[node*2+1]);
}
inline void lazytag(int node){
    if(segt[node].lazy){
        segt[node*2].val+=segt[node].lazy*(segt[node*2].R-segt[node*2].L+1);
        segt[node*2+1].val+=segt[node].lazy*(segt[node*2+1].R-segt[node*2+1].L+1);
        segt[node*2].lazy+=segt[node].lazy;
        segt[node*2+1].lazy+=segt[node].lazy;
    }
    return;
}
inline void update(int node,int L,int R,int k){
    if(L<=segt[node].L && segt[node].R<=R){
        segt[node].val=k;
        return;
    }
    //lazytag(node);

    int mid=(segt[node].L+segt[node].R)>>1;
    if(L<=mid){
        update(node*2,L,R,k);
    }
    if(mid<R){
        update(node*2+1,L,R,k);
    }
    segt[node].val=FUNC(segt[node*2],segt[node*2+1]);
    return;
}
inline int query(int node,int L,int R){
    if(L<=segt[node].L && segt[node].R<=R){
        return segt[node].val;  
    }
    //lazytag(node);
    int mid=(segt[node].L+segt[node].R)>>1;
    int res=MAX_RES;
    if(L<=mid){
        res=min(res,query(node*2,L,R));
    }
    if(mid<R){
        res=min(res,query(node*2+1,L,R));
    }
    return res;
}
//-template
int N,Q;
inline void solve(){
    N=read();Q=read();
    for(int i=1;i<=N;++i){
        arr[i]=read();
    }
    build(1,1,N);
    while(Q--){
        if(read()==1){
            int k=read(),u=read();
            update(1,k,k,u);
        }else{
            int a=read(),b=read();
            write(query(1,a,b));
            putchar('\n');
        }
    }
}
signed main(){
    solve();
    return 0;
}