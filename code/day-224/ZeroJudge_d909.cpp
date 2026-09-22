#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

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
//block
struct node{
    int rk,fa;
    node(int _r,int _f):rk(_r),fa(_f){};
};

int N,M,u,v,w,res;
vector<pair<int,pair<int,int>>>edges;
vector<node>nodes;
inline int fd(int x){
    if(nodes[x].fa==x){return x;}
    return nodes[x].fa=fd(nodes[x].fa);
}
inline bool un(int a,int b){
    a=fd(a);b=fd(b);

    if(a==b){return false;}

    if(nodes[a].rk>nodes[b].rk){
        nodes[b].fa=a;
        nodes[a].rk+=nodes[b].rk+1;
    }else{
        nodes[a].fa=b;
        nodes[b].rk+=nodes[a].rk+1;
    }
    return true;
}

signed main(){
    while(N=read()){
        M=read();
        edges.clear();
        nodes.clear();
        for(int i=0;i<M;++i){
            u=read();v=read();w=read();
            edges.push_back({w,{u,v}});
        }
        sort(edges.begin(),edges.end());

        for(int i=0;i<N;++i){
            nodes.push_back({0,i});
        }

        res=0;
        for(int i=0;i<M;++i){
            if(un(edges[i].second.second,edges[i].second.first)){res+=edges[i].first;}
        }

        write(res);
        putchar('\n');
    }
    return 0;
}
