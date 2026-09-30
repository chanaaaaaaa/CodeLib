#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//block
const int d[4][2]={
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};
const char direct[4]={'R','L','D','U'};
const int MAXN=50;//UVA
int T,z_x,z_y;
vector<char>S;
vector<vector<int>>dat(4,vector<int>(4,0));
inline bool valid(){
    vector<bool>check(16,false);
    int N=0;

    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            check[dat[i][j]]=true;
            if(dat[i][j]==0){
                z_y=i;
                z_x=j;
            }else{
                N+=count(check.begin()+1,check.begin()+dat[i][j],false);
            }
        }
    }
    for(int i=0;i<16;++i){
        if(!check[i]){return false;}
    }

    return !((N+(z_y+1))&1);
}
inline int make_limit(){
    int num=0;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(dat[i][j]==0){continue;}

            num+=abs((dat[i][j]-1)%4-j)+abs((dat[i][j]-1)/4-i);
        }
    }
    return num;
}

inline bool dfs(int cur,int pre_d,int bound){
    int lim=make_limit();
    if(lim==0){return true;}

    if(cur+lim>bound){return false;}

    for(int i=0;i<4;++i){
        if(i==(pre_d^1)){continue;}

        int ny=z_y+d[i][0];
        int nx=z_x+d[i][1];

        if(ny<0 || ny>=4 || nx<0 || nx>=4){continue;}

        S.emplace_back(direct[i]);
        swap(dat[ny][nx],dat[z_y][z_x]);
        swap(ny,z_y);
        swap(nx,z_x);

        if(dfs(cur+1,i,bound)){return true;}

        swap(ny,z_y);
        swap(nx,z_x);
        swap(dat[ny][nx],dat[z_y][z_x]);
        S.pop_back();
    }
    return false;
}
inline bool a_star(){
    for(int lim=make_limit();lim<=MAXN;++lim){
        if(dfs(0,-1,lim)){
            return true;
        }
    }
    return false;
}

signed main(){
    while(T=read()){
        while(T--){
            S.clear();
            for(int i=0;i<4;++i){
                for(int j=0;j<4;++j){
                    dat[i][j]=read();
                }
            }
            if(valid() && a_star()){
                for(char &c:S){
                    putchar(c);
                }
                putchar('\n');
            }else{
                puts("This puzzle is not solvable.");
            }
        }
    }
    return 0;
}
