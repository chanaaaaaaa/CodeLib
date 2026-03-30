#include <cstdio>
#include <algorithm>

#define int long long
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
        if(c=='-'){w=-1;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

const int MAXN=100005;
int N,a,b,x[MAXN],fx[MAXN],y[MAXN],fy[MAXN],prex[MAXN],prey[MAXN];

inline int solve(int i){
    int px=lower_bound(fx+1,fx+N+1,x[i])-fx-1;
    int py=lower_bound(fy+1,fy+N+1,y[i])-fy-1;

    return px*x[i]-prex[px]+prex[N]-prex[px]-(N-px)*x[i]+
           py*y[i]-prey[py]+prey[N]-prey[py]-(N-py)*y[i];
}

signed main(){
    while(N=read()){
        for(int i=1;i<=N;++i){
            a=read();b=read();
            x[i]=fx[i]=a+b;
            y[i]=fy[i]=a-b;
        }

        sort(fx+1,fx+N+1);
        sort(fy+1,fy+N+1);

        prex[0]=prey[0]=0;
        for(int i=1;i<=N;++i){
            prex[i]=prex[i-1]+fx[i];
            prey[i]=prey[i-1]+fy[i];
        }

        int res=0x7fffffffffffffff;
        for(int i=1;i<=N;++i){
            res=min(res,solve(i));
        }
        write(res/2);
        putchar('\n');
    }
    return 0;
}
