#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}

int H,W;
int dat[1005][1005];
int pfx_td[1005][1005];
int pfs_lr[1005][1005];

inline int boundary(int i,int j){
    if(i==0 && j==0){return dat[0][0];}
    if(i==0){return pfs_lr[0][j];}
    if(j==0){return pfx_td[i][0];}

    return pfs_lr[0][j]+pfs_lr[i][j]
            +pfx_td[i][0]+pfx_td[i][j]
            -dat[0][0]-dat[0][j]
            -dat[i][0]-dat[i][j];
}

signed main() {
    while(H=read()){
        W=read();
        for(int i=0;i<H;++i){
            for(int j=0;j<W;++j){
                char c=0;
                while(c>'9' || c<'0'){c=getchar();}
                dat[i][j]=(c=='1');

                pfs_lr[i][j]=dat[i][j]+(j?pfs_lr[i][j-1]:0);
                pfx_td[i][j]=dat[i][j]+(i?pfx_td[i-1][j]:0);
            }
        }
        int ans=0;
        for(int i=0;i<H;++i){
            for(int j=0;j<W;++j){
                ans=max(ans,boundary(i,j));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
