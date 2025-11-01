#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")

#include<cstdio>
#include<queue>
#include<utility>
#include<memory.h>

#define INF 100000000
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0'||c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
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
int T,N,M,
    mp[1001][1001],
    vals[1001][1001],
    d[2][4]={{1,-1,0,0},{0,0,1,-1}};
bool vis[1001][1001];
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
inline void solve(){
    vals[0][0]=mp[0][0];
    pq.push({mp[0][0],{0,0}});

    while(!pq.empty()){
        int val=pq.top().first,
            x=pq.top().second.first,
            y=pq.top().second.second;

        pq.pop();
        vis[x][y]=true;

        for(int f=0;f<4;++f){
            int nx=x+d[0][f];
            int ny=y+d[1][f];

            if(nx>=0 && nx<N && ny>=0 && ny<M && !vis[nx][ny]){
                int nv=mp[nx][ny]+val;
                if(vals[nx][ny]>nv || vals[nx][ny]==-1){
                    vals[nx][ny]=nv;
                    pq.push({nv,{nx,ny}});
                }
            }
        }
    }
}


signed main(){
    T=read();
    while(T--){
        N=read(),M=read();
        memset(mp,0,sizeof(mp));
        memset(vis,false,sizeof(vis));
        memset(vals,-1,sizeof(vals));
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                mp[i][j]=read();
            }
        }

        solve();
        write(vals[N-1][M-1]);
        putchar('\n');
    }

    return 0;
}
