#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

inline int read(){
    int x=0,c=0,w=1;
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
//-
const int MAXN=2e5+20;
struct nds{
    int sumA,ReqTime;
    int Ls,Rs;
}segt[MAXN<<2];
int N,Q;
vector<int>allB;
vector<pair<int,int>>dat;
vector<pair<int,pair<int,int>>>query;


inline int get_id(int bval){
    auto it=lower_bound(allB.begin(),allB.end(),bval,greater<int>());
    return it-allB.begin()+1;
}

inline void build(int node,int L,int R){
    segt[node].Ls=L;
    segt[node].Rs=R;
    if(L==R){
        segt[node].sumA=dat[L].second;
        segt[node].ReqTime=dat[L].second+dat[L].first;
        return;
    }

    int mid=(L+R)>>1;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);

    segt[node].sumA=segt[node*2].sumA+segt[node*2+1].sumA;
    segt[node].ReqTime=max(segt[node*2].ReqTime,segt[node*2].sumA+segt[node*2+1].ReqTime);
    return;
}




signed main(){
    while(N=read()){
        Q=read();
        dat.assign(N+1,pair<int,int>());//{B,A}
        query.assign(Q,pair<int,pair<int,int>>());
        allB.clear();

        for(int i=1;i<=N;++i){dat[i].second=read();}
        for(int i=1;i<=N;++i){
            dat[i].first=read();
            allB.push_back(dat[i].first);
        }

        for(int i=0;i<Q;++i){
            int type=read();
            int pos=read();
            int x=read();

            query[i]={type,{pos,x}};
            if(type==2){
                allB.push_back(x);
            }
        }
        sort(allB.begin(),allB.end(),greater<int>());
        allB.erase(unique(allB.begin(),allB.end()),allB.end());
        int sz=allB.size();
    }
    return 0;
}
