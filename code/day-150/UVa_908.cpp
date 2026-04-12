#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-ferun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-function-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}
//-block
const int MAXN=1e5;

struct edge{
    int p1,p2,v;
    bool treeedge;
    edge(int _p1,int _p2,int _v,bool _t): p1(_p1),p2(_p2),v(_v),treeedge(_t){}
    edge(){}
};
struct node{
    int parent,rk;
};

vector<edge>EdgeList;
map<int,node>NodeList;
inline int findset(int x){
    if(NodeList[x].parent==x){return x;}
    return NodeList[x].parent=findset(NodeList[x].parent);
}
inline int kruskal(){
    int res=0;
    for(edge &e:EdgeList){
        NodeList[e.p1].rk=0;
        NodeList[e.p1].parent=e.p1;

        NodeList[e.p2].rk=0;
        NodeList[e.p2].parent=e.p2;
    }

    for(edge &e:EdgeList){
        int a=findset(e.p1);
        int b=findset(e.p2);
        if(a!=b){
            e.treeedge=true;
            res+=e.v;

            if(NodeList[a].rk > NodeList[b].rk){
                NodeList[b].parent=a;
            }else{
                NodeList[a].parent=b;
                if(NodeList[a].rk==NodeList[b].rk){
                    ++NodeList[b].rk;
                }
            }
        }
    }
    EdgeList.clear();
    NodeList.clear();

    return res;
}

inline bool cmp(edge &a,edge &b){
    return a.v < b.v;
}

signed main(){
    int N;
    bool f=false;
    while(true){
        N=read()-1;
        if(N==-1){break;}
        if(f){
            putchar('\n');
        }else{
            f=true;
        }
        //
        for(int i=0;i<N;++i){
            EdgeList.push_back({read(),read(),read(),false});
        }
        sort(EdgeList.begin(),EdgeList.end(),cmp);
        write(kruskal());
        putchar('\n');
        //
        N=read();
        for(int i=0;i<N;++i){
            EdgeList.push_back({read(),read(),read(),false});
        }
        N=read();
        for(int i=0;i<N;++i){
            EdgeList.push_back({read(),read(),read(),false});
        }
        sort(EdgeList.begin(),EdgeList.end(),cmp);
        write(kruskal());
        putchar('\n');
        //
    }
    return 0;
}
