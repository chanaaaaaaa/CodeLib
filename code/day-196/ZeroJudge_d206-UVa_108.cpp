#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <cstdio>
#include <vector>

#define int long long
using namespace std;

inline int read(){
    int x=0,w=1,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
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
//-block
inline int max(const int &a,const int &b){
    return a>b?a:b;
}
int N;
vector<vector<int>>mp;
signed main(){
    while(N=read()){
        mp.assign(N+1,vector<int>(N+1));
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                mp[i][j]=read();
            }
        }

        //han
        for(int i=1;i<=N;++i){
            for(int j=2;j<=N;++j){
                mp[i][j]+=mp[i][j-1];
            }
        }
        //ze
        for(int j=1;j<=N;++j){
            for(int i=2;i<=N;++i){
                mp[i][j]+=mp[i-1][j];
            }
        }

        //search
        int maxx=-10000000;
        for(int si=0;si<N;++si){
            for(int sj=0;sj<N;++sj){
                for(int ei=si+1;ei<=N;++ei){
                    for(int ej=sj+1;ej<=N;++ej){
                        maxx=max(maxx,mp[ei][ej]+mp[si][sj]-mp[si][ej]-mp[ei][sj]);
                    }
                }
            }
        }
        write(maxx);
        putchar('\n');
    }
    return 0;
}
