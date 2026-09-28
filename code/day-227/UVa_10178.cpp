#include <cstdio>
#include <vector>
using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
        if(c>='A' && c<='Z'){return c-'A';}
        if(c>='a' && c<='z'){return c-'a'+26;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//
const int MAXN=52;

struct nds{
    int fa,rk;
    nds(int _f,int _r):fa(_f),rk(_r){}
};
vector<nds>nodes(MAXN,{0,0});
int N,M,st,ed,cnt;

inline int fd(int x){
    if(nodes[x].fa==x){return x;}
    return nodes[x].fa=fd(nodes[x].fa);
}
inline bool un(int a,int b){
    a=fd(a);b=fd(b);

    if(a==b){return true;}

    if(nodes[a].rk>nodes[b].rk){
        nodes[b].fa=a;
        nodes[a].rk+=nodes[b].rk+1;
    }else{
        nodes[a].fa=b;
        nodes[b].rk+=nodes[a].rk+1;
    }
    return false;
}

signed main(){
    while(N=read()){
        M=read();

        for(int i=0;i<MAXN;++i){
            nodes[i].fa=i;
            nodes[i].rk=0;
        }
        cnt=0;

        for(int i=0;i<M;++i){
            st=read();ed=read();

            if(un(st,ed)){++cnt;}
        }

        write(cnt+1);
        putchar('\n');
    }
    return 0;
}
