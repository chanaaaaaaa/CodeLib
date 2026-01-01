#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u,v,w;
};
vector<Edge>edge;
vector<int>father;
int n,m,k;

inline void add(int _u,int _v,int _w){
    Edge tmp;
    tmp.u=_u;tmp.v=_v;tmp.w=_w;
    edge.push_back(tmp);
}
inline int Find(int x){
    if(father[x]==x){
        return x;
    }else{
        return father[x]=Find(father[x]);
    }
}
inline void Merge(int x,int y){
    x=Find(x);
    y=Find(y);
    father[x]=y;
}
inline bool cmp(Edge &A,Edge &B){
    return A.w<B.w;
}

signed main(){
    while(cin>>n>>m>>k){
        father.reserve(n+1);
        for(int i=0;i<=n;++i){
            father[i]=i;
        }
        for(int i=0;i<m;++i){
            int u,v,w;
            cin>>u>>v>>w;
            add(u,v,w);
        }
        //Kruskal
        sort(edge.begin(),edge.end(),cmp);
        for(int i=1;i<=m;++i){
            int xr=Find(edge[i].u);
            int yr=Find(edge[i].v);
            if(xr!=yr){
                Merge(xr,yr);
            }
        }
        //-Kruskal
    }
    return 0;
}
