#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
using namespace std;

int R,C,K,M,d,maxx=0,minn=0x7fffffff;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        if(c=='-') w=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
signed main(){

    R=read();
    C=read();
    K=read();
    M=read();
    //scanf("%d %d %d %d",&R,&C,&K,&M);
    int now[R][C];
    int nex[R][C];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            //scanf("%d",&nex[i][j]);
            nex[i][j]=read();
        }
    }
    while(M--){
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                now[i][j]=nex[i][j];
            }
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                d=now[i][j]/K;
                if(now[i][j]==-1 || d==0)continue;
                for(int k=0;k<4;k++){
                    if(i+dy[k]>=0 && i+dy[k]<R && j+dx[k]>=0 && j+dx[k]<C){
                        if(now[i+dy[k]][j+dx[k]]==-1)continue;
                        nex[i+dy[k]][j+dx[k]]+=d;
                        nex[i][j]-=d;
                    }
                }
            }
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(nex[i][j]>=0){
                if(nex[i][j]>maxx)maxx=nex[i][j];
                if(nex[i][j]<minn)minn=nex[i][j];
            }
        }
    }
    write(minn);
    putchar('\n');
    write(maxx);
    return 0;
}
