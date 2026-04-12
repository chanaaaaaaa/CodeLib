//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<queue>

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
int P,F;

vector<vector<int>>peo;
vector<int>walked;
vector<int>day;
queue<int>wait;
signed main(){
    while(P=read()){
        peo.assign(P,vector<int>());
        for(int i=0;i<P;i++){
            F=read();
            while(F--){
                peo[i].emplace_back(read());
            }
        }
        F=read();
        while(F--){
            day.clear();
            walked.clear();
            walked.assign(P+1,-1);
            day.assign(P+1,0);
            wait.push(read());
            if(peo[wait.front()].size()==0){
                wait.pop();
                putchar('0');
                putchar('\n');
                continue;
            }
            walked[wait.front()]=0;
            while(!wait.empty()){
                int now=wait.front();
                wait.pop();
                for(auto &v:peo[now]){
                    if(walked[v]==-1){
                        walked[v]=walked[now]+1;
                        wait.push(v);
                        ++day[walked[v]];
                    }
                }
            }
            int mx=0,md=0;
            for(int i=1;i<=P;i++){
                if(day[i]>mx){
                    mx=day[i];
                    md=i;
                }
            }

            write(mx);
            putchar(' ');
            write(md);
            putchar('\n');
        }
        peo.clear();
    }
    return 0;
}

