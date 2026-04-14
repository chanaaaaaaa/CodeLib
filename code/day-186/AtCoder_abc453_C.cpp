#include <cstdio>
#include <vector>
//#include <utility>

using namespace std;

inline int read(){
    int x=0,c=0,w=1;
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
//-block
int res=0,N;
vector<long long>dat;

inline void dfs(int times,int dep,long double pos){
    if(dep==N){
        if(times > res){
            res=times;
        }
        return;
    }
    //dfs(times,dep+1,pos+dat[dep]);
    //dfs(times,dep+1,pos-dat[dep]);
    if(pos > 0){
        if(pos - dat[dep] < 0){
            dfs(times+1,dep+1,pos-dat[dep]);
        }else{
            dfs(times,dep+1,pos-dat[dep]);
        }
        dfs(times,dep+1,pos+dat[dep]);
    }else if(pos < 0){
        if(pos + dat[dep] > 0){
            dfs(times+1,dep+1,pos+dat[dep]);
        }else{
            dfs(times,dep+1,pos+dat[dep]);
        }
        dfs(times,dep+1,pos-dat[dep]);
    }
    return;
}

signed main(){
    N=read();
    dat.assign(N,0);

    for(int i=0;i<N;++i){
        dat[i]=read();
    }
    dfs(0,0,0.5);
    write(res);
    putchar('\n');
    return 0;
}
