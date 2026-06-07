#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int INF=1e9;

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

inline void write(int x) {
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}


struct Node{
    int min_d,max_d,max_l,max_r,ans;
    Node(){
        min_d=max_d=max_l=max_r=ans=-INF;
    }
};

int N,Q;
vector<vector<int>>adjL;
vector<bool>color;
vector<int>depth;
vector<int>pos;
vector<int>euler;
vector<Node>tree;

inline void dfs(int cur,int fa,int d){
    depth[cur]=d;
    pos[cur]=euler.size();
    euler.push_back(cur);
    for(int nxt:adjL[cur]){
        if(nxt!=fa){
            dfs(nxt,cur,d+1);
            euler.push_back(cur);
        }
    }
}

inline Node merge(const Node& L,const Node& R){
    Node res;
    res.min_d=min(L.min_d,R.min_d);
    res.max_d=max(L.max_d,R.max_d);
    res.max_l=max({L.max_l,R.max_l,L.max_d-2*R.min_d});
    res.max_r=max({L.max_r,R.max_r,R.max_d-2*L.min_d});
    res.ans=max({L.ans,R.ans,L.max_l+R.max_d,L.max_d+R.max_r});
    return res;
}

inline void build(int node,int l,int r){
    if(l==r){
        int u=euler[l];
        tree[node].min_d=depth[u];
        if(l==pos[u] && !color[u]){
            tree[node].max_d=depth[u];
            tree[node].max_l=-depth[u];
            tree[node].max_r=-depth[u];
            tree[node].ans=0;
        }else{
            tree[node].max_d=-INF;
            tree[node].max_l=-INF;
            tree[node].max_r=-INF;
            tree[node].ans=-INF;
        }
        return;
    }
    int mid=(l+r)>>1;
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    tree[node]=merge(tree[node<<1],tree[node<<1|1]);
}

inline void update(int node,int l,int r,int idx,int u){
    if(l==r){
        tree[node].min_d=depth[u];
        if(l==pos[u] && !color[u]){
            tree[node].max_d=depth[u];
            tree[node].max_l=-depth[u];
            tree[node].max_r=-depth[u];
            tree[node].ans=0;
        }else{
            tree[node].max_d=-INF;
            tree[node].max_l=-INF;
            tree[node].max_r=-INF;
            tree[node].ans=-INF;
        }
        return;
    }
    int mid=(l+r)>>1;
    if(idx<=mid){
        update(node<<1,l,mid,idx,u);
    }else{
        update(node<<1|1,mid+1,r,idx,u);
    }
    tree[node]=merge(tree[node<<1],tree[node<<1|1]);
}

signed main(){
    while(N=read()){
        adjL.assign(N+1,vector<int>());
        color.assign(N+1,false);
        for(int i=0;i<N-1;++i){
            int u=read();
            int v=read();
            adjL[u].emplace_back(v);
            adjL[v].emplace_back(u);
        }

        depth.assign(N+1,0);
        pos.assign(N+1,0);
        euler.clear();

        if(N>0){
            dfs(1,0,0);
            tree.assign(4*euler.size(),Node());
            build(1,0,euler.size()-1);
        }

        int black_cnt=N;

        Q=read();
        while(Q--){
            int st=read();
            color[st]=!color[st];

            if(color[st]){
                black_cnt--;
            }else{
                black_cnt++;
            }

            if(N>0){
                update(1,0,euler.size()-1,pos[st],st);
            }

            if(black_cnt<=1){
                write(0);
            }else{
                write(max(0,tree[1].ans));
            }
            putchar('\n');
        }
    }
    return 0;
}
