#include <cstdio>
#include <vector>
#include <algorithm>

#define int long long
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
inline bool cmp(const int a,const int b){
    return a>b;
}

signed main(){
    int N=read();
    int M=read();
    vector<int>shari(N);
    vector<int>neta(M);

    for(int i=0;i<N;++i){
        shari[i]=read();
    }
    for(int i=0;i<M;++i){
        neta[i]=read();
    }
    sort(shari.begin(),shari.end(),cmp);
    sort(neta.begin(),neta.end(),cmp);

    int p1=0,p2=0,res=0;
    while(p1<N && p2<M){
        if(shari[p1]*2 >= neta[p2]){
            ++p1;
            ++p2;
            ++res;
        }else{
            ++p2;
        }
    }
    write(res);
    putchar('\n');
    return 0;
}
