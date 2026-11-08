#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//block
const int MAXN=13;
struct nds{
    int rk,fa;
}nodes[MAXN];

inline int fd(int x){
    if(nodes[x].fa==x){return x;}
    return nodes[x].fa=fd(nodes[x].fa);
}
inline bool un(int a,int b){
    a=fd(a);b=fd(b);

    if(a==b){
        return false;
    }

    if(nodes[a].rk>nodes[b].rk){
        nodes[b].fa=a;
        nodes[a].rk+=nodes[b].rk;
    }else{
        nodes[a].fa=b;
        nodes[b].rk+=nodes[a].rk;
    }

    return true;
}

vector<pair<int,pair<int,int>>>dat;
int N,M,K,u,v,w;
signed main(){
    while(N=read()){
        M=read();K=read();
        for(int i=1;i<=N;++i){
            nodes[i].rk=1;
            nodes[i].fa=i;
        }

        dat.assign(M,pair<int,pair<int,int>>());
        for(int i=0;i<M;++i){
            dat[i].second.first=read();
            dat[i].second.second=read();
            dat[i].first=read();
        }
        sort(dat.begin(),dat.end());

        int tree_cnt=N,res=0;

        for(vector<pair<int,pair<int,int>>>::iterator it=dat.begin();it!=dat.end();++it){
            if(un(it->second.first,it->second.second)){
                --tree_cnt;
                res+=it->first;

                if(tree_cnt==K){break;}
            }
        }

        if(tree_cnt!=K){
            write(res);
        }else{
            putchar('-');
            putchar('1');
        }
        putchar('\n');

    }
    return 0;
}
