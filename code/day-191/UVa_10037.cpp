#include <cstdio>
#include <vector>
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
vector<int>route;
int T,N,res;
signed main(){
    T=read();
    while(T--){
        N=read();
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
            write(peo[0]);
            putchar('\n');
            if(T){putchar('\n');}
            continue;
        }else if(N==2){
            write(peo[1]);
            putchar('\n');
            write(peo[0]);
            putchar(' ');
            write(peo[1]);
            putchar('\n');
            if(T){putchar('\n');}
            continue;
        }else if(N==3){
            write(peo[2]+peo[0]+peo[1]);
            putchar('\n');
            write(peo[0]);
            putchar(' ');
            write(peo[2]);
            putchar('\n');
            write(peo[0]);
            putchar('\n');
            write(peo[0]);
            putchar(' ');
            write(peo[1]);
            putchar('\n');
            if(T){putchar('\n');}
            continue;
        }

        route.clear();
        res=0;
        --N;
        for(;N>=3;N-=2){
            int c1=peo[1]+peo[0]+peo[N]+peo[1];
            int c2=peo[N]+peo[0]+peo[N-1]+peo[0];
            if(c1<c2){
                res+=c1;
                route.emplace_back(peo[0]);
                route.emplace_back(peo[1]);
                route.emplace_back(peo[0]);

                route.emplace_back(peo[N-1]);
                route.emplace_back(peo[N]);
                route.emplace_back(peo[1]);
            }else{
                res+=c2;
                route.emplace_back(peo[0]);
                route.emplace_back(peo[N]);
                route.emplace_back(peo[0]);

                route.emplace_back(peo[0]);
                route.emplace_back(peo[N-1]);
                route.emplace_back(peo[0]);
            }
        }

        if(N==1){
            res+=peo[1];
            route.emplace_back(peo[0]);
            route.emplace_back(peo[1]);
        }else if(N==2){
            res+=peo[2]+peo[0]+peo[1];
            route.emplace_back(peo[0]);
            route.emplace_back(peo[2]);
            route.emplace_back(peo[0]);

            route.emplace_back(peo[0]);
            route.emplace_back(peo[1]);
        }

        write(res);
        putchar('\n');
        write(route[0]);
        putchar(' ');
        write(route[1]);
        putchar('\n');
        for(int i=4;i<route.size();i+=3){
            write(route[i-2]);
            putchar('\n');
            write(route[i-1]);
            putchar(' ');
            write(route[i]);
            putchar('\n');
        }

        if(T){putchar('\n');}
    }
    return 0;
}
