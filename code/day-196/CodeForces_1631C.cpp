#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")

#include <cstdio>
#include <vector>

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
    return;
}

int N,K;
inline void solve() {
    N=read();K=read();

    if(K==N-1 && N==4){
        putchar('-');
        putchar('1');
        putchar('\n');
        return;
    }

    vector<int>P(N);
    for(int i=0;i<N;i++){P[i]=i;}

    if(K==N-1){
        swap(P[N-1],P[N-2]);
        swap(P[1],P[N-3]);
        swap(P[0],P[2]);
    }else{
        swap(P[0],P[K]);
    }

    vector<bool>vis(N,false);
    for(int i=0;i<N;i++){
        if(!vis[i]){
            int target=i^(N-1);
            vis[i]=vis[target]=true;
            write(P[i]);
            putchar(' ');
            write(P[target]);
            putchar('\n');
        }
    }

    return;
}

int T;
signed main(){
    T=read();
    while(T--){
        solve();
    }
    return 0;
}
