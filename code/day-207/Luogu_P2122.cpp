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
inline void write(long long x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}
//-node
//-block
const int MAXN=1e5+50;
int arr[MAXN];
struct nd{
    int L,R;
    long long val,pwsum,lazy;
}segt[MAXN<<2];

inline void build(int node,int L,int R){
    segt[node].L=L;
    segt[node].R=R;
    if(segt[node].L==segt[node].R){
        segt[node].val=arr[segt[node].L];
        segt[node].pwsum=segt[node].val*segt[node].val;
        segt[node].lazy=0;
        return;
    }

    int mid=(L+R)>>1;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);

    segt[node].val=segt[node*2].val+segt[node*2+1].val;
    segt[node].pwsum=segt[node*2].pwsum+segt[node*2+1].pwsum;

    return;
}
inline void lazytag(int node){
    if(segt[node].lazy){
        segt[node*2].pwsum+=2*segt[node].lazy*segt[node*2].val+segt[node].lazy*segt[node].lazy*(segt[node*2].R-segt[node*2].L+1);
        segt[node*2].val+=segt[node].lazy*(segt[node*2].R-segt[node*2].L+1);
        segt[node*2].lazy+=segt[node].lazy;

        segt[node*2+1].pwsum+=2*segt[node].lazy*segt[node*2+1].val+segt[node].lazy*segt[node].lazy*(segt[node*2+1].R-segt[node*2+1].L+1);
        segt[node*2+1].val+=segt[node].lazy*(segt[node*2+1].R-segt[node*2+1].L+1);
        segt[node*2+1].lazy+=segt[node].lazy;

        segt[node].lazy=0;
    }
    return;
}
inline void update(int node,int L,int R,int k){
    if(L<=segt[node].L && segt[node].R<=R){
        segt[node].pwsum+=2*k*segt[node].val+k*k*(segt[node].R-segt[node].L+1);
        segt[node].val+=k*(segt[node].R-segt[node].L+1);
        segt[node].lazy+=k;
        return;
    }
    if(R<segt[node].L || segt[node].R<L){return;}
    lazytag(node);

    int mid=(segt[node].L+segt[node].R)>>1;
    if(L<=mid){
        update(node*2,L,R,k);
    } 
    if(mid<R){
        update(node*2+1,L,R,k);
    }

    segt[node].val=segt[node*2].val+segt[node*2+1].val;
    segt[node].pwsum=segt[node*2].pwsum+segt[node*2+1].pwsum;

    return;
}
inline long long query(int node,int L,int R,int mode){
    if(L<=segt[node].L && segt[node].R<=R){
        if(mode==2){
            return segt[node].val;
        }else if(mode==3){
            return segt[node].pwsum;
        }
    }
    if(R<segt[node].L || segt[node].R<L){return 0;}
    lazytag(node);

    int mid=(segt[node].L+segt[node].R)>>1;
    long long res=0;
    if(mode==2){
        if(L<=mid){
            res+=query(node*2,L,R,2);
        }
        if(mid<R){
            res+=query(node*2+1,L,R,2);
        }
    }else if(mode==3){
        if(L<=mid){
            res+=query(node*2,L,R,3);
        }
        if(mid<R){
            res+=query(node*2+1,L,R,3);
        }
    }
    return res;
}
//-template
inline long long gcd(const long long a,const long long b){
    return a?gcd(b%a,a):b;
}
inline void output(long long top,long long bot){
    if(top==0){
        putchar('0');
        putchar('/');
        putchar('1');
    }else{
        long long gd=gcd(top,bot);
        write(top/gd);
        putchar('/');
        write(bot/gd);
    }
    putchar('\n');
    return;
}
int N,M;
inline void solve(){
    N=read();M=read();
    for(int i=1;i<=N;++i){
        arr[i]=read();
    }
    build(1,1,N);
    while(M--){
        int type=read(),x=read(),y=read();
        if(type==1){
            int d=read();
            update(1,x,y,d);
        }else if(type==2){
            output(query(1,x,y,2),y-x+1);
        }else if(type==3){
            //res=(pwsm*(y-x+1)-sum*sum)/(y-x+1)^2
            long long sum=query(1,x,y,2);
            output(query(1,x,y,3)*(y-x+1)-sum*sum,(y-x+1)*(y-x+1));
        }
    }
    return;
}
signed main(){
    solve();
    return 0;
}