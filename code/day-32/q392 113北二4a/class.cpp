//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0'||c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//--block
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>route;
vector<vector<int>>lib;
int vals[5000];
bool vis[5000];
int mp[5000];
int L,S,E;

inline void dij(){
    vals[]
}

signed main(){
    while(L=read()){
        S=read();E=read();
        lib.assign(L,vector<int>(4));
        for(int i=0;i<L;i++){
            lib[i][2]=read();//Start
            lib[i][3]=read();//End
            lib[i][1]=read();//Time
            lib[i][0]=read();//Value
            //Value,Time,Start,End
        }

    }
    return 0;
}

