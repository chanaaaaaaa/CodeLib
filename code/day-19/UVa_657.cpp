//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>
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
inline void write(long long x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
int dx[4]={1,-1,0,0},
    dy[4]={0,0,1,-1},
    mp[50][50],
    W,H,cnt,cases;
queue<pair<int,int>>wtm;
vector<int>step;

inline int read_char(){
    char c=0;
    while(c!='.' && c!='*' && c!='X'){
        c=getchar();
    }
    if(c=='.'){return 0;}
    if(c=='*'){return 1;}
    if(c=='X'){return 2;}
}
inline void dfs(int y,int x){
    if(x<0 || y<0 || x>=W || y>=H || mp[y][x]!=2){return;}
    mp[y][x]=1;
    for(int f=0;f<4;f++){
        dfs(y+dy[f],x+dx[f]);
    }
}
inline int bfs(){
    int cnt=0;
    if(mp[wtm.front().first][wtm.front().second]==2){
        dfs(wtm.front().first,wtm.front().second);
        cnt++;
    }
    while(!wtm.empty()){
        int x=wtm.front().second;
        int y=wtm.front().first;
        wtm.pop();
        for(int f=0;f<4;f++){
            if(x+dx[f]>=0 && x+dx[f]<W && y+dy[f]>=0 && y+dy[f]<H){
                if(mp[y+dy[f]][x+dx[f]]==1){
                    mp[y+dy[f]][x+dx[f]]=0;
                    wtm.push({y+dy[f],x+dx[f]});
                }else if(mp[y+dy[f]][x+dx[f]]==2){
                    wtm.push({y+dy[f],x+dx[f]});
                    //mp[y+dy[f]][x+dx[f]]=4;
                    dfs(y+dy[f],x+dx[f]);
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main(){

    while(W=read()){
        if(W==-1){break;}
        H=read();
        if(H+W==0){break;}
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                mp[i][j]=read_char();
            }
        }
        //-input
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(mp[i][j]==1 || mp[i][j]==2){
                    wtm.push({i,j});

                    step.emplace_back(bfs());/*
                    for(int i=0;i<H;i++){
                        for(int j=0;j<W;j++){
                            write(mp[i][j]);
                        }
                        putchar('\n');
                    }
                    putchar('\n');*/
                }
            }
        }
        //output
        putchar('T');
        putchar('h');
        putchar('r');
        putchar('o');
        putchar('w');
        putchar(' ');
        write(++cases);
        putchar('\n');
        sort(step.begin(),step.end());
        for(int i=0;i<step.size();i++){
            if(i!=0){putchar(' ');}
            write(step[i]);
        }
        step.clear();
        putchar('\n');
        putchar('\n');
    }
    return 0;
}
