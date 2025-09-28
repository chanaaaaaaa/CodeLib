#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<queue>
#include<vector>
#include<memory.h>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int R,C,mp[1002][1002],sx,sy,ex,ey;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0'&& c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

int bfs(){
    queue<pair<int,int>>wait;
    wait.push({sx,sy});
    mp[sx][sy]=1;
    while(!wait.empty()){
        auto [ux,uy]=wait.front();
        wait.pop();
        for(int i=0;i<4;i++){
            int nx=ux+dx[i];
            int ny=uy+dy[i];
            if((nx>=0)&&(nx<R)&&(ny>=0)&&(ny<C)&& mp[nx][ny]==0){
                mp[nx][ny]=mp[ux][uy]+1;
                if(nx==ex && ny==ey){return mp[ex][ey]-1;}
                wait.push({nx,ny});
            }
        }
    }
    return -1;
}
signed main(){
    while(R=read(),C=read(), R && C){
        int N=read();

        memset(mp,0,sizeof(mp));
        while(N--){
            int r=read(),k=read();
            while(k--){
                mp[r][read()]=-1;
            }
        }
        //bfs
        sx=read(),sy=read(),ex=read(),ey=read();
        write(bfs());
        putchar('\n');
    }
    return 0;
}
