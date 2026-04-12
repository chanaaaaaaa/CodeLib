#include <cstdio>
#include <vector>
#include <utility>
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
    return;
}
//-block
inline int max(const int &a,const int &b){
    return a>b?a:b;
}

int N,M,x,y,w,res;
vector<vector<pair<int,int>>>mp;
vector<bool>vis;
inline void dfs(int cur,int wgt){
    bool bad=true;
    for(pair<int,int> &p:mp[cur]){
        if(vis[p.first]){continue;}

        vis[p.first]=true;
        dfs(p.first,wgt+p.second);
        vis[p.first]=false;
        bad=false;
    }
    if(bad){
        res=max(res,wgt);
    }
    return;
}
signed main(){
    while(N=read()){
        mp.assign(N,vector<pair<int,int>>());
        vis.assign(N,false);
        res=0;
        M=read();
        while(M--){
            x=read();y=read();w=read();
            mp[x-1].push_back({y-1,w});
            mp[y-1].push_back({x-1,w});
        }
        for(int i=0;i<N;++i){
            vis[i]=true;
            dfs(i,0);
            vis[i]=false;
        }
        write(res);
        putchar('\n');
    }
    return 0;
}
