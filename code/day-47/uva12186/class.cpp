#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>

#define MAXN 1e5+10
#define int long long
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
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
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
int N,prctge;//total employee, the request accept percentage
vector<vector<int>>lib;
vector<int>dat;
inline int solve(int father){//base on the request accept percentage to solve the problem
    if(lib[father].size()==0){return 1;}
    priority_queue<int,vector<int>,greater<int>>pqe;
    for(auto &n:lib[father]){
        pqe.push(solve(n));
    }
    int res=0;
    for(int i=0;i<dat[father];++i){
        res+=pqe.top();
        pqe.pop();
    }
    return res;
}
signed main(){
    while(true){
        N=read();prctge=read();
        if(N+prctge==0){break;}

        lib.clear();
        dat.clear();
        lib.assign(MAXN,vector<int>());
        dat.assign(MAXN,0);

        for(int i=1;i<=N;++i){
            lib[read()].push_back(i);
        }
        for(int i=0;i<N;++i){
            dat[i]=(int)ceil(1.0*lib[i].size()*prctge/100);
        }
        write(solve(0));
        putchar('\n');
    }
    return 0;
}
/*
3 100
0 0 0
3 50
0 0 0
14 60
0 0 1 1 2 2 2 5 7 5 7 5 7 5
0 0
*/
