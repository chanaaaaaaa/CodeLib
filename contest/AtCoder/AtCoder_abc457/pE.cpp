#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include <cstdio>
#include <vector>
#include <algorithm>

#define int long long
using namespace std;

inline int read(){
    int x=0,w=1,c=0;
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
}
//  1  2  3  4
//a 2  1
//m 1     1  1
signed main(){
    int N=read(),M=read();
    vector<vector<int>>st_at(N+1);
    vector<vector<int>>ed_at(N+1);
    for(int i=0;i<M;++i){
        int a=read(),b=read();
        st_at[a].push_back(b);
        ed_at[b].push_back(a);
    }
    for(int i=1;i<=N;++i){
        if(st_at[i].size()){sort(st_at[i].begin(),st_at[i].end());}
        if(ed_at[i].size()){sort(ed_at[i].begin(),ed_at[i].end());}
    }
    int Q=read();
    while(Q--){
        int st=read(),ed=read();
        vector<int>::iterator Ra=upper_bound(st_at[st].begin(),st_at[st].end(),ed);
        if(Ra==st_at[st].begin()){
            putchar('N');
            putchar('o');
            putchar('\n');
            continue;
        }
        vector<int>::iterator Lb=lower_bound(ed_at[ed].begin(),ed_at[ed].end(),st);
        if(Lb==ed_at[ed].end()){
            putchar('N');
            putchar('o');
            putchar('\n');
            continue;
        }

        if(*prev(Ra)>=*Lb-1){
            if(*prev(Ra)==ed && *Lb==st){
                int cntA=Ra-st_at[st].begin();
                int cntB=ed_at[ed].end()-Lb;
                if(cntA==1 && cntB==1){
                    putchar('N');
                    putchar('o');
                    putchar('\n');
                    continue;
                }
            }
            putchar('Y');
            putchar('e');
            putchar('s');
            putchar('\n');
        }else{
            putchar('N');
            putchar('o');
            putchar('\n');
        }
    }
    return 0;
}
