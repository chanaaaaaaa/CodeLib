#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='.'){return 0;}
        if(c=='#'){return -1;}
        if(c=='A'){return -2;}
        if(c=='B'){return -3;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//
int d[2][4]={
    {1,-1,0,0},
    {0,0,1,-1}
};
signed main(){
    int N=read(),M=read(),res;
    vector<vector<int>>mp(N,vector<int>(M,0));
    pair<int,int>ed;
    queue<pair<int,int>>Q;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            int check=read();
            if(check==-2){
                Q.push({i,j});
                mp[i][j]=1;
            }else if(check==-3){
                ed={i,j};
            }else{
                mp[i][j]=check;
            }
        }
    }
    //exe
    while(!Q.empty()){
        int y=Q.front().first,
            x=Q.front().second;
        Q.pop();
        for(int f=0;f<4;++f){
            int dy=y+d[0][f],
                dx=x+d[1][f];
            if(dy>=0 && dy<N && dx>=0 && dx<M && mp[dy][dx]==0){
                mp[dy][dx]=mp[y][x]+1;
                Q.push({dy,dx});
            }
        }
    }
    //-exe
    res=-1;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(mp[i][j]>0){
                bool canFindB=false;
                int steps=mp[i][j]-1;

                if(i==ed.first){
                    int minCol=min(j,ed.second);
                    int maxCol=max(j,ed.second);
                    bool hasWall=false;

                    for(int k=minCol+1;k<maxCol;++k){
                        if(mp[i][k]==-1){
                            hasWall=true;
                            break;
                        }
                    }
                    if(!hasWall){
                        canFindB=true;
                    }
                }
                if(j==ed.second){
                    int minRow=min(i,ed.first);
                    int maxRow=max(i,ed.first);
                    bool hasWall=false;
                    for(int k=minRow+1;k<maxRow;++k){
                        if(mp[k][j]==-1){
                            hasWall=true;
                            break;
                        }
                    }
                    if(!hasWall){
                        canFindB=true;
                    }
                }

                if(canFindB && (res==-1 || steps<res)){
                    res=steps;
                }
            }
        }
    }
    write(res);
    putchar('\n');
    return 0;
}
