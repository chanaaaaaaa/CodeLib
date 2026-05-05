#include <cstdio>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;

inline ll read(){
    int c=0;
    ll x=0,w=1;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
        if(c=='-'){w=-1;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*w;
}
inline void write(ll x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
const int MAXN=5e4+50;
struct Edg{
    int u,v,nxt;
    ll w,pr;
}edge[MAXN];
int d[MAXN],head[MAXN],cur[MAXN],cnt;
int s,n,t,m;

inline void init(){
    cnt=0;
    memset(head,-1,sizeof(head));
}
inline void add(int u,int v,int w,int p){
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
            ll p=edge[i].pr;
            if(!d[v] && w){
                d[v]=d[top]+1;
                Q.push(v);
            }
        }
    }
}