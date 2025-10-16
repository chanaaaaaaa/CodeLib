#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<queue>
#include<utility>
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return -1;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
inline int read_char(){
    int x=0;
    char c=0;
    while(c!='*'&&c!='@'){
        c=getchar();
    }
    if(c=='@'){return 1;}
    else{return 0;}
}
int dx[8]={0,0,1,-1,1,1,-1,-1},
    dy[8]={1,-1,0,0,1,-1,-1,1},
    n,m,cnt,x,y;
queue<pair<int,int>>wait;

int main(){
    while(n=read(),m=read()){
        //if(n+m==0){break;}
        int mp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i][j]=read_char();
            }
        }
        cnt=0;
        for(int i=0;i<n;i++){//y
            for(int j=0;j<m;j++){//x
                if(mp[i][j]){
                    cnt++;
                    wait.push({i,j});
                    while(!wait.empty()){
                        y=wait.front().first;
                        x=wait.front().second;
                        mp[y][x]=0;
                        wait.pop();
                        for(int f=0;f<8;f++){
                            if(x+dx[f]>=0 && x+dx[f]<m && y+dy[f]>=0 && y+dy[f]<n){
                                if(mp[y+dy[f]][x+dx[f]]){
                                    wait.push({y+dy[f],x+dx[f]});
                                }
                            }
                        }
                    }
                }
            }
        }
        write(cnt);
        putchar('\n');
    }
    return 0;
}
