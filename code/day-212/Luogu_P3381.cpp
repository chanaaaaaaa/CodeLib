#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

typedef long long ll;
using namespace std;

inline ll read() {
    ll x=0;
    int c=0,w=1;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x*w;
}

inline void write(ll x){
    if(x<0){putchar('-'),x=-x;}
    if (x>=10){write(x/10);}
    putchar(x%10+'0');
}

const int MAXN=5005;
const int MAXM=100005;

const ll INFD=0x3f3f3f3f3f3f3f3fLL;
const ll INFF=(ll)4e18;

int n,m,tot;
int lnk[MAXN],cur[MAXN];
int ter[MAXM],nxt[MAXM];
ll cap[MAXM];
int cost[MAXM];
ll dis[MAXN];
bool vis[MAXN];
ll mincost;

inline void add(int u, int v,ll w, int c){
    ter[++tot]=v;
    nxt[tot]=lnk[u];
    lnk[u]=tot;
    cap[tot]=w;
    cost[tot]=c;

    ter[++tot]=u;
    nxt[tot]=lnk[v];
    lnk[v]=tot;
    cap[tot]=0;
    cost[tot]=-c;
}

inline bool spfa(int s,int t){
    memset(dis,0x3f,sizeof(dis));
    memcpy(cur,lnk,sizeof(lnk));
    queue<int>Q;

    dis[s]=0;
    vis[s]=true;
    Q.push(s);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        vis[u]=false;
        for(int i=lnk[u];i;i=nxt[i]){
            int v=ter[i];
            if(cap[i] && dis[v]>dis[u]+cost[i]){
                dis[v]=dis[u]+cost[i];
                if(!vis[v]){
                    vis[v]=true;
                    Q.push(v);
                }
            }
        }
    }
    return dis[t] < INFD>>2;
}

inline ll dfs(int u,int t,ll flow){
    if(u==t){return flow;}
    vis[u]=true;
    ll ans=0;
    for(int &i=cur[u];i && ans<flow;i=nxt[i]){
        int v=ter[i];
        if(!vis[v] && cap[i] && dis[v]==dis[u]+cost[i]){
            ll x=dfs(v,t,min(cap[i],flow-ans));
            if(x){
                mincost+=x*cost[i];
                cap[i]-=x;
                cap[i^1]+=x;
                ans+=x;
            }
        }
    }
    vis[u]=false;
    return ans;
}

inline ll mcmf(int s,int t) {
    ll maxflow=0;
    while(spfa(s,t)){
        ll x;
        while((x=dfs(s,t,INFF))){maxflow+=x;}
    }
    return maxflow;
}

signed main(){
    int s,t;
    n=(int)read();
    m=(int)read();
    s=(int)read();
    t=(int)read();
    while(m--){
        int u=(int)read(),v=(int)read(),cst;
        ll w=read();
        cst=(int)read();
        add(u,v,w,cst);
    }
    ll ans=mcmf(s,t);
    write(ans);
    putchar(' ');
    write(mincost);
    putchar('\n');
    return 0;
}
