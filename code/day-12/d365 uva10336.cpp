#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<queue>
#define int long long
using namespace std;

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
// -block
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

inline int read_char(){
    char c=0;
    while(c<'a' || c>'z'){
        c=getchar();
    }
    return c-'a';
}

signed main(){
    int N=read();
    for(int T=1;T<=N;T++){
        int H=read(),W=read();
        int mp[H][W],dat[27]={0};
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                mp[i][j]=read_char();
            }
        }
        //-init&input
        //bfs
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(mp[i][j]!=-1){
                    int target=mp[i][j];
                    queue<pair<int,int>>wait;
                    wait.push({i,j});
                    dat[target]++;
                    while(!wait.empty()){
                        /*
                        //test
                        for(int ti=0;ti<H;ti++){
                            for(int tj=0;tj<W;tj++){
                                putchar(mp[ti][tj]);
                                putchar(' ');
                            }
                            putchar('\n');
                        }
                        //-test
                        */
                        int y=wait.front().first;
                        int x=wait.front().second;
                        wait.pop();
                        mp[y][x]=-1;
                        for(int k=0;k<4;k++){
                            if(y+dy[k]>=0 && y+dy[k]<H && x+dx[k]>=0 && x+dx[k]<W){
                                if(mp[y+dy[k]][x+dx[k]]==target){
                                    wait.push({y+dy[k],x+dx[k]});
                                }
                            }
                        }
                    }
                }
            }
        }
        //output
        putchar('W');
        putchar('o');
        putchar('r');
        putchar('l');
        putchar('d');
        putchar(' ');
        putchar('#');
        write(T);
        putchar('\n');
        for(int i=0;i<26;i++){
            int maxx=26;
            for(int j=0;j<26;j++){
                if(dat[j]>dat[maxx]){maxx=j;}
            }
            if(maxx==26){break;}
            putchar('a'+maxx);
            putchar(':');
            putchar(' ');
            write(dat[maxx]);
            putchar('\n');
            dat[maxx]=0;
        }
    }
    return 0;
}
