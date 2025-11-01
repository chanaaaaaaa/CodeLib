#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<utility>
#include<unordered_set>
#include<climits>
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0'||c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//--block
vector<vector<pair<int,int>>>Edges;
vector<int>stoc;
vector<int>dist;
unordered_set<int>walked;
int Node_N,Edge_N,End_N,cases=0,
    u,v,endpos;

inline int pow3(int x){
    return x*x*x;
}

inline void solve(){
    dist[1]=0;
    for(int i=0;i<Node_N-1;++i){
        for(int u=0;u<=Node_N;++u){
            for(auto&[v,w]:Edges[u]){
                if(dist[u]!=INT_MAX){
                    dist[v]=min(dist[v],dist[u]+w);
                }
            }
        }
    }
    for(int u=1;u<=Node_N;++u){
        for(auto&[v,w]:Edges[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                walked.emplace(v);
            }
        }
    }

}

signed main(){

    while(Node_N=read()){
        //init
        Edges.assign(Node_N+1,vector<pair<int,int>>());
        stoc.assign(201,0);
        dist.assign(201,INT_MAX);
        //-init
        //input
        for(int i=1;i<=Node_N;i++){
            stoc[i]=read();
        }
        Edge_N=read();
        for(int i=0;i<Edge_N;i++){
            u=read();v=read();
            Edges[u].push_back({v,pow3(stoc[v]-stoc[u])});
        }
        //-input
        solve();
        //output
        putchar('S');
        putchar('e');
        putchar('t');
        putchar(' ');
        putchar('#');
        write(++cases);
        putchar('\n');

        End_N=read();
        while(End_N--){
            endpos=read();
            if(walked.count(endpos) || dist[endpos]<3 || dist[endpos]==INT_MAX){
                putchar('?');
            }else{write(dist[endpos]);}
            putchar('\n');
        }
        //-output
        //clear
        Edges.clear();
        stoc.clear();
        dist.clear();
        walked.clear();
    }
    return 0;
}
