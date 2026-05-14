#include <cstdio>
#include <vector>
using namespace std;

inline int read() {
    int x=0;
    int c=0,w=1;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x*w;
}

inline void write(int x){
    if(x<0){putchar('-'),x=-x;}
    if (x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
inline int min(const int a,const int b){
    return a<b?a:b;
}
inline int max(const int a,const int b){
    return a>b?a:b;
}
const int INF=0x3f3f3f3f;

signed main(){
    int C,S,Q,cases=0;
    vector<vector<int>>adjL;
    while(true){
        C=read();
        S=read();
        Q=read();
        if(C==0 && S==0 && Q==0){break;}
        adjL.assign(C+1,vector<int>(C+1,INF));

        for(int i=0;i<S;++i){
            int u=read();
            int v=read();
            int w=read();
            adjL[u][v]=adjL[v][u]=w;
        }

        for(int k=1;k<=C;++k){
            for(int i=1;i<=C;++i){
                for(int j=1;j<=C;++j){
                    adjL[i][j]=min(adjL[i][j],max(adjL[i][k],adjL[k][j]));
                }
            }
        }
        
        if(cases){putchar('\n');}
        printf("Case #%d\n",++cases);
        while(Q--){
            int u=read();
            int v=read();
            if(adjL[u][v]==INF){
                printf("no path\n");
            }else{
                write(adjL[u][v]);
                putchar('\n');
            }
        }
    }
    return 0;
}
