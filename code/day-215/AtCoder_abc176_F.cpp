#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>

#define int long long
using namespace std;

inline int read(){
    int x=0,w=1,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
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
}
//-block
const int MAXN=2e3+10;
int N,e,res=0;
int dat[MAXN*3];
int look[3];
int dp[MAXN][MAXN];
int tr[MAXN];

struct node{
    int x,y,z;
};
vector<node>V;

signed main(){
    N=read();
    for(int i=1;i<=N*3;++i){
        dat[i]=read();
    }
    memset(dp,0xcf,sizeof(dp));
    memset(tr,0xcf,sizeof(tr));

    dp[dat[1]][dat[2]]=
    dp[dat[2]][dat[1]]=
    tr[dat[1]]=
    tr[dat[2]]=
    tr[dat[2]]=e=0;

    for(int i=3;i<N*3;i+=3){
        for(int j=0;j<3;++j){look[j]=dat[i+j];}
        sort(look,look+3);V.clear();

        if(look[0]==look[1] && look[1]==look[2]){++res;continue;}
        if(look[0]==look[1] || look[1]==look[2]){
            if(look[1]==look[2]){swap(look[0],look[2]);}
            for(int j=1;j<=N;++j){V.push_back({j,look[2],max(tr[j],dp[j][look[0]]+1)});}
            for(int j=1;j<=N;++j){V.push_back({j,look[0],tr[j]});}
            V.push_back({look[0],look[0],max(e,dp[look[2]][look[2]]+1)});
            V.push_back({look[0],look[2],e});
        }else{
            for(int j=0;j<3;++j){
                for(int k=1;k<=N;++k){V.push_back({k,look[j],tr[k]});}
            }
            for(int j=0;j<3;++j){
                V.push_back({look[j],look[(j+2)%3],max(e,dp[look[(j+1)%3]][look[(j+1)%3]]+1)});
            }
        }

        for(int j=0;j<V.size();++j){
            tr[V[j].x]=max(tr[V[j].x],dp[V[j].x][V[j].y]=max(dp[V[j].x][V[j].y],V[j].z));
            if(V[j].x!=V[j].y){
                tr[V[j].y]=max(tr[V[j].y],dp[V[j].y][V[j].x]=dp[V[j].x][V[j].y]);
            }
            e=max(e,dp[V[j].x][V[j].y]);
        }
    }
    write(max(e,dp[dat[N*3]][dat[N*3]]+1)+res);
    putchar('\n');
    return 0;
}
