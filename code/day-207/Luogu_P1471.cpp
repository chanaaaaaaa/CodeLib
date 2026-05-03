#include <stdio.h>
#include <math.h>
using namespace std;

//-block

//-func
const int MAXN=1e5+10;
long double arr[MAXN];
struct nd{
    int L,R;
    long double val,pwsum,lazy;
}segt[MAXN<<2];

inline void build(int node,int L,int R){
    segt[node].L=L;
    segt[node].R=R;
    if(segt[node].L==segt[node].R){
        segt[node].val=arr[segt[node].L];
        segt[node].pwsum=arr[segt[node].L]*arr[segt[node].L];
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
    if(segt[node].lazy!=0.0){
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
inline void update(int node,int L,int R,long double k){
    if(L<=segt[node].L && segt[node].R<=R){
        segt[node].pwsum+=2*k*segt[node].val+k*k*(segt[node].R-segt[node].L+1);
        segt[node].val+=k*(segt[node].R-segt[node].L+1);
        segt[node].lazy+=k;
        return;
    }
    if(R<segt[node].L || L>segt[node].R){return;}
    lazytag(node);

    int mid=(segt[node].R+segt[node].L)>>1;
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
inline long double query(int node,int L,int R,int mode){
    if(L<=segt[node].L && segt[node].R<=R){
        if(mode==1){
            return segt[node].val;
        }else if(mode==3){
            return segt[node].pwsum;
        }
    }
    if(R<segt[node].L || L>segt[node].R){return 0.0;}
    lazytag(node);

    int mid=(segt[node].R+segt[node].L)>>1;
    long double res=0;
    if(mode==1){
        if(L<=mid){
            res+=query(node*2,L,R,1);
        }
        if(mid<R){
            res+=query(node*2+1,L,R,1);
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
int N,M;
inline void solve(){
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;++i){
        scanf("%Lf",&arr[i]);
    }
    build(1,1,N);
    while(M--){
        int type,x,y;
        long double k;
        scanf("%d %d %d",&type,&x,&y);
        if(type==1){
            scanf("%Lf",&k);
            update(1,x,y,k);
        }else if(type==2){
            long double sum=query(1,x,y,1);
            printf("%.4f\n",(double)sum/(y-x+1));
        }else{
            long double sum=query(1,x,y,1);
            long double pwsm=query(1,x,y,3);
            //res^2=sigma(i=x)(y)[(X_i-avg)^2]
            //res^2=sigma(i=x)(y)[X_i^2-2*X_i*avg+avg^2]
            //res^2=pwsm-2*val*avg+avg*avg*N;
            long double res=(pwsm-sum*sum/(y-x+1))/(y-x+1);
            printf("%.4f\n",(double)res);
        }
    }
}

signed main(){
    solve();
    return 0;
}
