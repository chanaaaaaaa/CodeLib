#include <cstdio>
#include <memory.h>

using namespace std;

inline int read(){
    int x=0,c=0,w=1;
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
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}

int N,M,T;
bool vis[100],nxt[100],f;

signed main(){
    while(T=read()){
        while(T--){
            N=read();M=read();
            memset(vis,false,sizeof(vis));
            vis[0]=true;
            f=false;

            for(int i=0,r;i<N;i++){
                r=read()%M;
                if(f){continue;}

                for(int j=0;j<M;j++){
                    if(!vis[j]){continue;}
                    nxt[(j+r+M)%M]=true;
                    nxt[(j-r+M)%M]=true;
                }

                f=true;
                for(int j=0;j<M;j++){
                    vis[j]=nxt[j];
                    if(!nxt[j]){
                        f=false;
                    }else{
                        nxt[j]=0;
                    }
                }
            }
            if(vis[0]){
                printf("Divisible\n");
            }else{
                printf("Not divisible\n");
            }
        }
    }
    return 0;
}
