#include <cstdio>
#include <vector>
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='.'){return 1;}
        if(c=='#'){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
signed main(){
    int N=read(),res;
    vector<vector<int>>mp(N,vector<int>(N,0));
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            mp[i][j]=read();
        }
    }
    //res
    res=0;
    for(int i=0;i<N;++i){//y
        for(int j=0;j<N;++j){//x
            if(mp[i][j]){
                int d=1;
                while(j+d<N && i+d<N){
                    if(mp[i][j+d] && mp[i+d][j] && mp[i+d][j+d]){
                        ++res;
                    }
                    ++d;
                }
            }
        }
    }
    write(res);
    putchar('\n');
    return 0;
}
