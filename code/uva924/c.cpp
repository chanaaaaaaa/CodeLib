#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int E;
vector<vector<int>>dat;
inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0'&& c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

void bfs(int S){
    queue<int>wait;
    vector<int>con(E,-1);
    vector<int>day(E,0);
    int maxx=0,d=0;
    wait.emplace(S);
    con[S]=0;
    while(!wait.empty()){
        if(dat[wait.front()].size()){
            for(auto &v :dat[wait.front()]){
                if(con[v]==-1){
                    con[v]=con[wait.front()]+1;
                    wait.emplace(v);
                    day[con[v]]++;
                }
            }
        }
        wait.pop();
    }
    for(int i=0;i<day.size();i++){
        if(day[i]>maxx){maxx=day[i];d=i;}
    }

    if(maxx==0){
        putchar('0');
    }else{
        write(maxx);
        putchar(' ');
        write(d);
    }
    putchar('\n');
}
signed main(){
    E=read();

    dat.assign(E, vector<int>());
    for(int i=0;i<E;i++){
        int t=read();
        while(t--){
            dat[i].emplace_back(read());
        }
    }
    int T=read();
    while(T--){
        bfs(read());
        //write(bfs(s));
        //putchar('\n');
    }
    return 0;
}
