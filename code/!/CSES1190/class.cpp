#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inilne")
#pragma GCC optimize("-fgcse")
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
#include<cstdio>
#include<algorithm>
#include<vector>
#include<math.h>

#define MAXN 200010
#define int long long
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        if(c=='-'){w=-1;}
        c=getchar();
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
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
int N,M;
vector<int>seg_tree(MAXN*4);
vector<int>laz_targ(MAXN*4);
vector<int>ths_edit(MAXN*4);
vector<int>input(MAXN);

inline void build(int L,int R,int id){
    if(L==R){
        seg_tree[id]=input[L];
        return;
    }
    int m=L+((R-L)>>1);

    build(L,m,id*2);
    build(m+1,R,id*2+1);

    seg_tree[id]=seg_tree[id*2]+seg_tree[id*2+1];
}
inline void update(int L,int R,int uL,int uR,int id,int val){
    if(L>=uL&&R<=uR){
        seg_tree[p]=(R-L+1)*val,laz_targ[id]=c,ths_edit[id]=1;
        return;
    }
    int m=L+((R-L)>>1);
    if(ths_edit[id]){
        seg_tree[id*2]=laz_targ[id]*(m-L+1),
        seg_tree[id*2+1]=laz_targ[id]*(R-m);

        laz_targ[id*2]=laz_targ[id*2+1]=laz_targ[id];
        ths_edit[id*2]=ths_edit[id*2+1]=1;
        ths_edit[id]=0;
    }
    if(uL<=m){update(L,m,uL,uR,id*2,val);}
    if(m<uR){update(m+1,R,uL,uR,id*2+1,val);}
    seg_tree[id]=seg_tree[id*2]+seg_tree[id*2+1];
}
inline int query(int L,int R,int qL,int qR,int id){
    if(L>=qL&&R<=qR){
        return seg_tree[id];
    }
    int m=L+((R-L)>>1),sum=0;
    if(ths_edit[id]){
        seg_tree[id*2]=laz_targ[id]*(m-L+1),
        seg_tree[id*2+1]=laz_targ[id]*(R-m);

        laz_targ[id*2]=laz_targ[id*2+1]=laz_targ[id];
        ths_edit[id*2]=ths_edit[id*2+1]=1;
        ths_edit[id]=0;
    }

    if(qL<=m){sum+=query(L,m,qL,qR,id*2);}
    if(m<qR){sum+=query(m+1,R,qL,qR,id*2+1);}
    return sum;
}


signed main(){
    N=read();M=read();
    for(int i=1;i<=N;++i){
        input[i]=read();
    }
    build(1,N,1);
    int pre=pow(2,ceil(log2(N))+1);
    for(int i=0;i<pre;++i){
        write(seg_tree[i]);
        putchar(' ');
    }
    return 0;
}
