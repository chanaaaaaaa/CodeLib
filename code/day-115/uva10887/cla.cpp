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
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//-block
struct node{
    int cnt=0;
    bool rp=false;
    bool ed=false;
    node *n[26]={};
};

inline void add(node *root,string s){
    node *p=root;
    for(char &c:s){
        int i=c-'a';
        if(!p->n[i]){
            p->n[i]=new node();
        }
        p=p->n[i];
    }
    p->ed=true;
    ++p->cnt;
    return;
}
inline bool query(node *root,string s){
    node *p=root;
    for(char &c:s){
        int i=c-'a';
        if(!p->n[i]){
            return false;
        }
        p=p->n[i];
    }
    if(p->ed && p->cnt >= 1 && !p->rp){
        p->rp=true;
        return true;
    }
    return false;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    while(cin>>T){
        for(int i=1;i<=T;++i){
            int a,b;
            cin>>a>>b;cin.ignore();

            vector<string>va(a);
            vector<string>vb(b);
            vector<string>v;

            for(int j=0;j<a;++j){
                getline(cin,va[j]);
            }
            for(int j=0;j<b;++j){
                getline(cin,vb[j]);
            }

            node *root=new node();
            for(int j=0;j<a;++j){
                for(int k=0;k<b;++k){
                    v.push_back(va[j]+vb[k]);
                    add(root,va[j]+vb[k]);
                }
            }
            int res=0;
            for(string &s:v){
                if(query(root,s)){
                    ++res;
                }
            }

            cout<<"Case "<<i<<": "<<res<<'\n';
        }
    }
    return 0;
}
