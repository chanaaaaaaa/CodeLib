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
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

//-block
const int N=505;
const double pi=acos(-1.0);

int n,en;
double x,y;
struct seg{
    double x1,x2,y1,y2;
}s[N];
struct E{
    double t;
    int v;
}e[N*4];

inline bool isequal(double &a,double &b){
    return fabs(a-b)<1e-9;
}
inline bool cmp(E &a,E &b){
    if(!isequal(a.t,b.t)){return a.t<b.t;}
    return a.v>b.v;
}
inline void build(){
    en=0;
    for(int i=0;i<n;++i){
        double r1=atan2(s[i].y1-y,s[i].x1-x);
        double r2=atan2(s[i].y2-y,s[i].x2-x);
        if(r1>r2){swap(r1,r2);}
        if(r2-r1>=pi){
            e[en].t=-pi;e[en++].v=1;
            e[en].t=r1;e[en++].v=-1;
            r1=r2;r2=pi;
        }
        e[en].t=r1;e[en++].v=1;
        e[en].t=r2;e[en++].v=-1;
    }
    sort(e,e+en,cmp);
}
inline int solve(){
    int ans=0,num=0;
    for(int i=0;i<en;++i){
        num+=e[i].v;
        ans=max(ans,num);
    }
    return ans;
}
signed main(){
    while(~scanf("%d",&n) && n){
        for(int i=0;i<n;++i){
            scanf("%lf%lf%lf%lf",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
        }
        scanf("%lf%lf",&x,&y);
        build();
        printf("%d\n",solve());
    }
    return 0;
}
