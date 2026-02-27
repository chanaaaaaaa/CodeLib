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
#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

struct node{
    bool vis;
    int val;
    node *let_n,*rit_n;
    node() : vis(false),val(0),let_n(NULL),rit_n(NULL){}
};

node *root=NULL;
bool die=false;

inline node* newnode() {
    return new node();
}

inline void insertnode(int k,char *c){
    if(!root){root=newnode();}
    node *p=root;

    while(*c && *c!=')'){
        if(*c=='L'){
            if(p->let_n==NULL){p->let_n=newnode();}
            p=p->let_n;
        }else if(*c=='R'){
            if(p->rit_n==NULL){p->rit_n=newnode();}
            p=p->rit_n;
        }
        ++c;
    }

    if(p->vis){die=true;}
    p->val=k;
    p->vis=true;

    return;
}

inline void clean(node *nd){
    if(nd==NULL){return;}
    clean(nd->let_n);
    clean(nd->rit_n);
    delete nd;
}

inline bool read_input(){
    char s[1000];
    die=false;
    clean(root);
    root=newnode();

    while(scanf("%s",s)==1){
        if(strcmp(s,"()")==0){return true;}
        int val;
        sscanf(&s[1],"%d",&val);
        insertnode(val,strchr(s, ',')+1);
    }
    return false;
}

inline void bfs() {
    if(die){printf("not complete\n");return;}

    vector<int>ans;
    queue<node*>q;
    q.push(root);

    while (!q.empty()) {
        node* curr=q.front();
        q.pop();

        if(!curr->vis){
            printf("not complete\n");
            return;
        }

        ans.push_back(curr->val);
        if(curr->let_n){q.push(curr->let_n);}
        if(curr->rit_n){q.push(curr->rit_n);}
    }

    for(int i=0;i<ans.size();++i){
        printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    }
}

signed main(){
    while(read_input()){
        bfs();
    }
    return 0;
}
