#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
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
}
//-block
inline int max(const int a,const int b){
    return a>b?a:b;
}

const int MAXN=3e5+10;

int xl[MAXN];
int yl[MAXN];

int xx[MAXN];
int yy[MAXN];

signed main(){
    int H=read();
    int W=read();
    int N=read();
    int maxx=0,maxy=0;


    for(int i=0;i<N;++i){
        int x=read();
        int y=read();

        xl[i]=x;
        yl[i]=y;

        ++xx[x];
        ++yy[y];
        maxx=max(maxx,xx[x]);
        maxy=max(maxy,yy[y]);
    }

    int cnt=0;
    for(int i=0;i<N;++i){
        int x=xl[i];
        int y=yl[i];
        if(xx[x]==maxx && yy[y]==maxy){++cnt;}
    }
    int sumx=0,sumy=0;
    for(int i=1;i<=H;++i){
        if(xx[i]==maxx){
            ++sumx;
        }
    }
    for(int i=1;i<=W;++i){
        if(yy[i]==maxy){
            ++sumy;
        }
    }
    if(sumx*sumy==cnt){
        write(maxx+maxy-1);
    }else{
        write(maxx+maxy);
    }
    putchar('\n');

    return 0;
}
