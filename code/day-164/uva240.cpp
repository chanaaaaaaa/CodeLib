#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
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

#include <cstdio>
#include <cstdlib>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
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
/* I/O Optimize */
const int LLINF=0x7fffffffffffffffLL;
int R,N,T;
int frequency[27],frequensum;
string codes[27];

long long expval;
double avgval;

struct node{
    long long dfn=LLINF;
    int letter=0;
    int weight=0;
    vector<node>nex;

    bool operator < (const node &x)const{
        if(weight==x.weight){return dfn>x.dfn;}
        return weight>x.weight;
    }
};
node root;

inline void build(){
    priority_queue<node>minHaff;

    for(int i=0;i<N;++i){
        node tmp;
        tmp.letter=i;
        tmp.weight=frequency[i];
        tmp.dfn=i;
        minHaff.emplace(tmp);
    }

    int right=(N-1)%(R-1);
    if(right){right+=1;}

    node tmpRight;
    for(int i=0;i<right;++i){
        node tmp=minHaff.top();
        minHaff.pop();

        tmpRight.nex.emplace_back(tmp);
        tmpRight.weight+=tmp.weight;

        tmpRight.dfn=min(tmpRight.dfn,tmp.dfn);
    }
    if(tmpRight.weight){minHaff.emplace(tmpRight);}

    while(minHaff.size()>=R){
        node t;
        for(int i=0;i<R;++i){
            node cur=minHaff.top();minHaff.pop();

            t.nex.emplace_back(cur);
            t.weight+=cur.weight;

            t.dfn = min(t.dfn,cur.dfn);
        }
        minHaff.emplace(t);
    }

    root = minHaff.top();
    return;
}
inline void dfs(node &cur,string s,int dep){
    if(!cur.nex.size()){
        codes[cur.letter]=s;
        expval+=frequency[cur.letter]*dep;
        return;
    }

    // 依題目規則排序：頻率較低者優先，相同則字母序較早者優先
    sort(cur.nex.begin(), cur.nex.end(), [](const node &a, const node &b){
        if(a.weight != b.weight) return a.weight < b.weight;
        return a.dfn < b.dfn;
    });

    for(int i=0;i<cur.nex.size();++i){
        dfs(cur.nex[i], s+to_string(i+R-cur.nex.size()),dep+1);
    }
}
inline void createcode(){
    expval=0;
    dfs(root,"",0);
    avgval=1.0*expval/frequensum;
}
inline void solve(){
    while(R=read()){
        N=read();
        frequensum=0;
        for(int i=0;i<N;++i){
            frequency[i]=read();
            frequensum+=frequency[i];
        }

        build();
        createcode();

        printf("Set %d; average length %.2f\n",++T,avgval);
        for(int i=0;i<N;++i){
            printf("    %c: %s\n",i+'A',codes[i].c_str());
        }
        putchar('\n');
    }
}

/* Programing area*/
signed main(){
    solve();
    system("pause");
    return 0;
}
