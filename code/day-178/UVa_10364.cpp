#include <cstdio>
#include <vector>
#include <map>
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
//-block
int T,N;
map<int,int>dat;
map<int,int>mp;

inline void dfs(int dep,int sum){
    ++mp[sum];
    if(dep==N){return;}

    for(map<int,int>::iterator it=dat.begin();it!=dat.end();++it){
        --it->second;
        dfs(dep+1,sum+it->first);
        ++it->second;
    }
}

signed main(){
    while(T=read()){
        while(T--){
            N=read();
            dat.clear();
            mp.clear();
            for(int i=0;i<N;++i){
                ++dat[read()];
            }
            dfs(0,0);

            bool f=false;
            for(map<int,int>::iterator it=dat.begin();it!=dat.end();++it){
                if()
            }
        }
    }
    return 0;
}