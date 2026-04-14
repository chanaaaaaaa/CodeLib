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
inline int abs(const int &a){
    return a>0?a:-a;
}


signed main(){
    int T=read(),X=read(),tmp;
    vector<pair<int,int>>res;

    res.push_back({0,read()});
    for(int i=1;i<=T;++i){
        tmp=read();
        if(abs(tmp-res.back().second) >= X){
            res.push_back({i,tmp});
        }
    }
    for(pair<int,int> &p:res){
        write(p.first);
        putchar(' ');
        write(p.second);
        putchar('\n');
    }
    return 0;
}
