#include <cstdio>

//#define int long long
using namespace std;

inline int read(){
    int x=0,w=1,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}

        if(c=='A'){return 1;}
        if(c=='B'){return 2;}
        if(c=='C'){return 3;}
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
inline int min(const int &a,const int &b){
    return a<b?a:b;
}
inline int max(const int &a,const int &b){
    return a>b?a:b;
}
//-func
const int MAXN=5e5+50;
int arr[MAXN];
struct nd{
    int L,R,cA,cB,lazy;
}segt[MAXN<<2];

inline void build(int node,int L,int R){
    segt[node].L=L;
    segt[node].R=R;
    if(segt[node].L==segt[node].R){
        segt[node].cA=arr[segt[node].L];
        segt[node].cB=arr[segt[node].L];
        segt[node].lazy=0;
        return;
    }

    int mid=(L+R)>>1;

    build(node*2,L,mid);
    build(node*2+1,mid+1,R);

    segt[node].cA=min(segt[node*2].cA,segt[node*2+1].cA);
    segt[node].cB=max(segt[node*2].cB,segt[node*2+1].cB);
    return;
}
inline void lazytag(int node){
    if(!segt[node].lazy){return;}

    if(segt[node].L==segt[node].R){segt[node].lazy=0;return;}

    segt[node*2].cA=segt[node*2].cB=segt[node].lazy;
    segt[node*2].lazy=segt[node].lazy;
    segt[node*2+1].cA=segt[node*2+1].cB=segt[node].lazy;
    segt[node*2+1].lazy=segt[node].lazy;
    segt[node].lazy=0;
    return;
}
inline void update(int node,int L,int R,int k){
    
    if(R<segt[node].L || L>segt[node].R){return;}

    if(L<=segt[node].L && segt[node].R<=R){
        segt[node].cA=segt[node].cB=k;
        segt[node].lazy=k;
        return;
    }
    lazytag(node);
    
    int mid=(segt[node].L+segt[node].R)>>1;

    update(node*2,L,R,k);
    update(node*2+1,L,R,k);

    segt[node].cA=min(segt[node*2].cA,segt[node*2+1].cA);
    segt[node].cB=max(segt[node*2].cB,segt[node*2+1].cB);
    return;
}
inline int query(int node,int L,int R){
    if(L<=segt[node].L && segt[node].R<=R){
        if(segt[node].cA==segt[node].cB){
            return segt[node].cA;
        }else{
            return -1;
        }
    }
    lazytag(node);

    int mid=(segt[node].L+segt[node].R)>>1;
    int resA=-2,resB=-2;
    if(L<=mid){
        resA=query(node*2,L,R);
    }
    if(mid<R){
        resB=query(node*2+1,L,R);
    }
    if(resA==-2 && resB==-2){
        return -1;
    }else if(resA==-2){
        return resB;
    }else if(resB==-2){
        return resA;
    }else{
        if(resA!=resB){
            return -1;
        }else{
            return resA;
        }
    }
}
//-template
int N,K;
inline void solve(){
    N=read();
    for(int i=1;i<=N;++i){
        arr[i]=read();
    }
    build(1,1,N);
    K=read();
    while(K--){
        if(read()==1){
            int x=read(),y=read(),op=read();
            update(1,x,y,op);
        }else{
            int x=read(),y=read();
            int res=query(1,x,y);
            if(x>1 && y<N){
                if(query(1,x-1,x-1)==query(1,y+1,y+1)){
                    res=-1;
                }
            }

            if(res!=-1){
                putchar('Y');
                putchar('e');
                putchar('s');
            }else{
                putchar('N');
                putchar('o');
            }
            putchar('\n');
        }
    }
}
signed main(){
    solve();
    return 0;
}
