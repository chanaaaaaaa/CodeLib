#include<cstdio>

#define int long long
using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}

inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
const int MAXN=1e5+10;
int arr[MAXN];
struct node{
    int l,r;
    long long val,lazy;
}tree[MAXN<<2];

inline void build(int p,int l,int r){
    tree[p].l=l;
    tree[p].r=r;
    if(tree[p].l==tree[p].r){
        tree[p].val=arr[l];
        return;
    }

    int mid=(l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    tree[p].val=tree[p*2].val+tree[p*2+1].val;
}
inline void lazytag(int p){
    if(tree[p].lazy){
        tree[p*2].val+=tree[p].lazy*(tree[p*2].r-tree[p*2].l+1);
        tree[p*2+1].val+=tree[p].lazy*(tree[p*2+1].r-tree[p*2+1].l+1);
        tree[p*2].lazy+=tree[p].lazy;
        tree[p*2+1].lazy+=tree[p].lazy;
        tree[p].lazy=0;
    }
}
inline void update(int p,int l,int r,int k){
    if(l<=tree[p].l && tree[p].r<=r){
        tree[p].val+=k*(tree[p].r-tree[p].l+1);
        tree[p].lazy+=k;
        return;
    }
    lazytag(p);

    int mid=(tree[p].l+tree[p].r)>>1;
    if(l<=mid){
        update(p*2,l,r,k);
    }
    if(mid<r){
        update(p*2+1,l,r,k);
    }
    tree[p].val=tree[p*2].val+tree[p*2+1].val;
}
inline int query(int p,int l,int r){
    if(l<=tree[p].l && tree[p].r<=r){
        return tree[p].val;
    }
    lazytag(p);

    int mid=(tree[p].l+tree[p].r)>>1;
    int res=0;
    if(l<=mid){
        res+=query(p*2,l,r);
    }
    if(mid<r){
        res+=query(p*2+1,l,r);
    }
    return res;
}
//--template
int N,M,T;
inline void solve(){
    N=read();M=read();
    for(int i=1;i<=N;++i){
        arr[i]=read();
    }
    build(1,1,N);
    while(M--){
        if(read()==1){
            int x=read(),y=read(),p=read();
            update(1,x,y,p);
        }else{
            int x=read(),y=read();
            write(query(1,x,y));
            putchar('\n');
        }
    }
}
signed main(){
    solve();
    return 0;
}
