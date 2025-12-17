#include <cstdio>
#include <vector>
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
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
    bool flag=false;
    for(int i=0;i<N;++i){
        for(int j=0;j<N/2;++j){
            if(mp[i][j]!=mp[i][N-1-j]){
                flag=true;
                break;
            }
        }
        if(flag){break;}
    }
    if(flag){
        putchar('N');
        putchar('o');
    }else{
        putchar('Y');
        putchar('e');
        putchar('s');
    }
    putchar('\n');
    return 0;
}
