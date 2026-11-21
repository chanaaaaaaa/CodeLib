#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

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

inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

const int INF=1e9;
struct State{
    int pos,pre_col,dist;
};
int N,M,u,v,c;
signed main(){
    while((N=read())){
        M=read();
        vector<vector<pair<int,int>>>grid(N+1);
        for(int i=0;i<M;++i){
            u=read();v=read();c=read();
            grid[u].push_back({v,c});
        }

        vector<int>d1(N+1,INF),c1(N+1,-1),d2(N+1,INF);
        queue<State>Q;

        d1[1]=0;
        c1[1]=0;
        Q.push({1,0,0});

        while(!Q.empty()){
            auto &[cur,pre_col,d]=Q.front();
            Q.pop();

            if(cur==N){break;}

            for(auto &[nxt,nxt_col]:grid[cur]){
                if(pre_col==nxt_col){continue;}

                if(d1[nxt]==INF){
                    d1[nxt]=d+1;
                    c1[nxt]=nxt_col;
                    Q.push({nxt,nxt_col,d+1});
                }else if(d2[nxt]==INF && c1[nxt]!=nxt_col){
                    d2[nxt]=d+1;
                    Q.push({nxt,nxt_col,d+1});
                }
            }
        }

        if(d1[N]==INF){
            putchar('-');
            putchar('1');
        }else{
            write(d1[N]);
        }
        putchar('\n');
    }
    return 0;
}
