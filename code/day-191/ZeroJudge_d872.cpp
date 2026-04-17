#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

inline int read(){
    int x=0,c=0,w=1;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return -1;}
        if(c=='-'){w=-1;}
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

vector<int>peo;
int N,res;
signed main(){
    while(true){
        N=read();
        if(N==-1){break;}
        if(N==0){
            putchar('0');
            putchar('\n');
            continue;
        }
        peo.assign(N,0);
        for(int i=0;i<N;++i){
            peo[i]=read();
        }
        sort(peo.begin(),peo.end());

        if(N==1){
            write(peo[0]);
            putchar('\n');
            continue;
        }else if(N==2){
            write(peo[1]);
            putchar('\n');
            continue;
        }else if(N==3){
            write(peo[2]+peo[0]+peo[1]);
            putchar('\n');
            continue;
        }

        res=0;
        --N;
        for(;N>=3;N-=2){
            int c1=peo[1]+peo[0]+peo[N]+peo[1];
            int c2=peo[N]+peo[0]+peo[N-1]+peo[0];
            res+=min(c1,c2);
        }
    
        if(N==1){
            res+=peo[1];
        }else if(N==2){
            res+=peo[2]+peo[0]+peo[1];
        }

        write(res);
        putchar('\n');
    }
    return 0;
}
