#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>
//#define int long long
typedef long long ll;
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
inline void write(long long x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}
//-block
//-func
const int MAXN=1e6+100;
struct Edge{
    int nxt,u,v;
    ll w;
}edge[MAXN];
int d[MAXN],head[MAXN],cur[MAXN],cnt;
int s,n,t,m;

inline void init(){
    cnt=0;
    memset(head,-1,sizeof(head));
}
inline void add(int u,int v,int w){
    edge[cnt].v=v;
    edge[cnt].u=u;
    edge[cnt].w=w;
    edge[cnt].nxt=head[u];
    head[u]=cnt++;

    edge[cnt].v=u;
    edge[cnt].u=v;
    edge[cnt].w=0;
    edge[cnt].nxt=head[v];
    head[v]=cnt++;
}
inline bool bfs(int s,int t){
    queue<int>Q;
    memset(d,0,sizeof(d));
    Q.push(s);
    d[s]=1;
    while(!Q.empty()){
        int top=Q.front();
        Q.pop();
        for(int i=head[top];i!=-1;i=edge[i].nxt){
            int v=edge[i].v;
            ll w=edge[i].w;
            if(!d[v] && w){
                d[v]=d[top]+1;
                Q.push(v);
            }
        }
    }
    return d[t]>0;
}
inline ll dfs(int s,int t,ll inflow){
    if(s==t || !inflow){return inflow;}
    ll flow=0;
    for(int &i=cur[s];i!=-1;i=edge[i].nxt){
        int v=edge[i].v;
        ll w=edge[i].w;
        if(w && d[v]==d[s]+1){
            ll x=dfs(v,t,min(inflow,w));
            edge[i].w-=x;
            edge[i^1].w+=x;
            inflow-=x;
            flow+=x;
            if(!inflow){break;}
        }
    }
    if(!flow){d[s]=-2;}
    return flow;
}
inline ll dinic(int s,int t){
    ll res=0;
    while(bfs(s,t)){
        for(int i=1;i<=n;++i){cur[i]=head[i];}
        ll tmp;
        while(tmp=dfs(s,t,LLONG_MAX/4)){
            res+=tmp;
        }
    }
    return res;
}
signed main(){
    n=read();
    m=read();
    s=read();
    t=read();
    init();
    for(int i=1;i<=m;++i){
        int _u=read(),_v=read(),_w=read();
        add(_u,_v,_w);
    }
    write(dinic(s,t));
    putchar('\n');
    return 0;
}
