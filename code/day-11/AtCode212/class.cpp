#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<climits>
using namespace std;

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
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
// -block

signed main(){
    int N=read(),M=read();
    int DN[N],DM[M];
    for(int i=0;i<N;i++){
        DN[i]=read();
    }
    for(int i=0;i<M;i++){
        DM[i]=read();
    }
    sort(DN,DN+N);
    sort(DM,DM+M);
    //-input
    int idx_N=0,idx_M=0,minn=INT_MAX;
    while(idx_N<N && idx_M<M){
        minn=min(minn,abs(DN[idx_N]-DM[idx_M]));
        /*
        write(DN[idx_N]);
        putchar(' ');
        write(DM[idx_M]);
        putchar('\n');
        */
        if(DN[idx_N]==DM[idx_M]){
            minn=0;
            break;
        }else if(DN[idx_N]>DM[idx_M]){
            idx_M++;
        }else if(DN[idx_N]<DM[idx_M]){
            idx_N++;
        }
    }
    write(minn);
    putchar('\n');
    return 0;
}
