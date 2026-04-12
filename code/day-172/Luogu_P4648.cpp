#include <cstdio>
#include <vector>
#include <algorithm>

#define int long long
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
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
}
//-block

int B,N,D,M,res;
//B=1
inline void B_1(){
    vector<int>dat(N);
    for(int i=0;i<N;++i){
        dat[i]=read();
    }
    sort(dat.begin(),dat.end());

    int pos=0;
    for(int i=0;i<N;++i){
        while(pos<N && dat[pos]-dat[i]<=D){
            ++pos;
        }
        res+=(pos-i-1);
    }
    return;
}
//B=2
struct node{
    int u,v;
    node(int _u,int _v):u(_u),v(_v) {}
    node(){}
};
int offset,MAX_V;
vector<int>BIT;

inline void add(int index,int val){
    while(index < MAX_V){
        BIT[index]+=val;
        index+=(index & -index);
    }
}
inline int query(int index){
    if(index<0){return 0;}
    if(index >= MAX_V){index=MAX_V-1;}

    int sum=0;
    while(index>0){
        sum+=BIT[index];
        index-=(index & -index);
    }
    return sum;
}

inline bool cmp(const node &a,const node &b){
    return a.u < b.u;
}

inline void B_2(){
    vector<vector<int>>dat(N,vector<int>(2,0));
    for(int i=0;i<N;++i){
        dat[i][0]=read();
        dat[i][1]=read();
    }

    offset=M+1;
    MAX_V=M*2+2;
    BIT.assign(MAX_V,0);

    vector<node>nds(N);

    for(int i=0;i<N;++i){
        nds[i].u=dat[i][0]+dat[i][1];
        nds[i].v=dat[i][0]-dat[i][1]+offset;
    }
    sort(nds.begin(),nds.end(),cmp);

    int posL=0;
    for(int posR=0;posR<N;++posR){
        while(nds[posR].u-nds[posL].u > D){
            add(nds[posL].v,-1);
            ++posL;
        }

        int v_min=nds[posR].v-D;
        int v_max=nds[posR].v+D;
        res+=query(v_max)-query(v_min-1);
        add(nds[posR].v,1);
    }
}
//B=3
int M_MAX,MAX_U;
vector<vector<vector<int>>>cnt,prefix;
inline void B_3(){
    M_MAX=75;MAX_U=155;MAX_V=155;
    cnt.assign(M_MAX+1,vector<vector<int>>(MAX_U,vector<int>(MAX_V,0)));
    prefix.assign(M_MAX+1,vector<vector<int>>(MAX_U,vector<int>(MAX_V,0)));

    vector<vector<int>>dat(N,vector<int>(3,0));
    for(int i=0;i<N;++i){
        dat[i][0]=read();
        dat[i][1]=read();
        dat[i][2]=read();
    }

    for(int i=0;i<N;++i){
        int nx=dat[i][0];
        int ny=dat[i][1];
        int nz=dat[i][2];

        int nu=ny+nz;
        int nv=ny-nz+75;
        ++cnt[nx][nu][nv];
    }

    for(int x=1;x<=75;++x){
        for(int u=1;u<=150;++u){
            for(int v=1;v<=150;++v){
                prefix[x][u][v]=cnt[x][u][v]+
                                prefix[x][u-1][v]+
                                prefix[x][u][v-1]-
                                prefix[x][u-1][v-1];
            }
        }
    }

    for(int i=0;i<N;++i){
         int nx=dat[i][0];
         int nu=dat[i][1]+dat[i][2];
         int nv=dat[i][1]-dat[i][2]+75;

        for(int lx=1;lx<=75;++lx){
            int dL=D-abs(nx-lx);

            if(dL<0){continue;}

            int u_min=max((long long)1,nu-dL);
            int u_max=min((long long)150,nu+dL);
            int v_min=max((long long)1,nv-dL);
            int v_max=min((long long)150,nv+dL);

            res+=prefix[lx][u_max][v_max]-
                 prefix[lx][u_min-1][v_max]-
                 prefix[lx][u_max][v_min-1]+
                 prefix[lx][u_min-1][v_min-1];
        }
    }
    res=(res-N)/2;
    return;
}
signed main(){
    while(B=read()){
        N=read();D=read();M=read();res=0;
        if(B==1){
            B_1();
        }else if(B==2){
            B_2();
        }else if(B==3){
            B_3();
        }
        write(res);
        putchar('\n');
    }
    return 0;
}
