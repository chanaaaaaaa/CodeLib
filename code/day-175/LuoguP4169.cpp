#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int MAXN = 1e7+5; 
const double ALPHA = 0.75;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

int cmp_dim;

struct Node{
    int d[2],
        min_d[2],
        max_d[2],
        ls, rs,
        size;
}tree[MAXN];

int root,tot,ans;

inline bool cmp(const int &a,const int &b){
    return tree[a].d[cmp_dim] < tree[b].d[cmp_dim];
}

inline void pushup(int u) {
    int l=tree[u].ls, r=tree[u].rs;
    tree[u].size=tree[l].size+tree[r].size+1;
    for (int i=0;i<2;++i){
        tree[u].min_d[i]=tree[u].max_d[i]=tree[u].d[i];
        if(l){
            tree[u].min_d[i]=min(tree[u].min_d[i],tree[l].min_d[i]);
            tree[u].max_d[i]=max(tree[u].max_d[i],tree[l].max_d[i]);
        }
        if(r){
            tree[u].min_d[i]=min(tree[u].min_d[i],tree[r].min_d[i]);
            tree[u].max_d[i]=max(tree[u].max_d[i],tree[r].max_d[i]);
        }
    }
}

int build(int L,int R,int dim,vector<int> &g){
    if(L>R){return 0;}
    int mid=(L+R)>>1;
    cmp_dim=dim;
    
    nth_element(g.begin()+L,g.begin()+mid,g.begin()+R+1,cmp);
    
    int u=g[mid];
    tree[u].ls=build(L,mid-1,dim^1,g);
    tree[u].rs=build(mid+1,R,dim^1,g);
    pushup(u);
    return u;
}

void flatten(int u,vector<int> &g){
    if(!u){return;}
    g.push_back(u);
    flatten(tree[u].ls,g);
    flatten(tree[u].rs,g);
}

inline void check(int& u,int dim){
    int max_child_size=max(tree[tree[u].ls].size,tree[tree[u].rs].size);
    
    if(max_child_size>ALPHA*tree[u].size){
        vector<int>g;
        flatten(u,g);
        u=build(0,g.size()-1,dim,g); 
    }
}

inline int new_node(int x,int y){
    ++tot;
    tree[tot].d[0]=tree[tot].min_d[0]=tree[tot].max_d[0]=x;
    tree[tot].d[1]=tree[tot].min_d[1]=tree[tot].max_d[1]=y;
    tree[tot].ls=tree[tot].rs=0;
    tree[tot].size=1;
    return tot;
}

inline void insert(int &u,int pid,int dim){
    if(!u){
        u=pid;
        pushup(u);
        return;
    }
    
    if(tree[pid].d[dim]<=tree[u].d[dim]){
        insert(tree[u].ls,pid,dim^1);
    } else {
        insert(tree[u].rs,pid,dim^1);
    }
    
    pushup(u); 
    check(u,dim);
}

inline int get_min_dist(int u,int qx,int qy){
    if(!u){return 2e9;}
    int dist=0;
    if(qx<tree[u].min_d[0]){dist+=tree[u].min_d[0]-qx;}
    if(qx>tree[u].max_d[0]){dist+=qx-tree[u].max_d[0];}
    if(qy<tree[u].min_d[1]){dist+=tree[u].min_d[1]-qy;}
    if(qy>tree[u].max_d[1]){dist+=qy-tree[u].max_d[1];}
    return dist;
}

void query(int u,int qx,int qy){
    if(!u){return;}
    
    int current_dist=abs(tree[u].d[0]-qx)+abs(tree[u].d[1]-qy);
    ans=min(ans,current_dist);

    int dl=get_min_dist(tree[u].ls,qx,qy);
    int dr=get_min_dist(tree[u].rs,qx,qy);

    if(dl<dr){
        if(dl<ans){query(tree[u].ls,qx,qy);}
        if(dr<ans){query(tree[u].rs,qx,qy);}
    }else{
        if(dr<ans){query(tree[u].rs,qx,qy);}
        if(dl<ans){query(tree[u].ls,qx,qy);}
    }
}

int N,M;

signed main(){
    while(N=read()){
        root=0;tot=0;
        M=read();
        while(N--){
            insert(root,new_node(read(),read()),0);
        }
        while(M--){
            int f=read();
            if(f==1){
                insert(root,new_node(read(),read()),0);
            }else{
                ans=2e9;
                query(root,read(),read());
                write(ans);
                putchar('\n');
            }
        }
        putchar('\n');
    }
    return 0;
}