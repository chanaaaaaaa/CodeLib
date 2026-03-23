#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<queue>
#include<utility>
#include<string>
using namespace std;

inline int read_num(){
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
inline int read_block(){//dic-> 0=space / 1=A / -8=B / -1=Z / -2=X
    char c=0;
    while(c!='.' && c!='B' && c!='A' && c!='Z'){
        c=getchar();
    }
    if(c=='.'){return 0;}
    if(c=='A'){return 1;}
    if(c=='B'){return -8;}
    if(c=='Z'){return -1;}
    return 9;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
inline void say(string x){
    for(int i=0;i<x.size();i++){
        putchar(x[i]);
    }
}
// -block

int hx[8]={1,-1,2,-2,2,-2,1,-1};
int hy[8]={2,2,1,1,-1,-1,-2,-2};

int px[8]={1,0,-1,1,-1,1,0,-1};
int py[8]={1,1,1,0,0,-1,-1,-1};
signed main(){
    int t=read_num();
    while(t--){
        //init
        queue<pair<int,int>>wait;
        int m=read_num(),n=read_num();
        int mp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i][j]=read_block();
                if(mp[i][j]==1){wait.push({i,j});}
            }
        }
        //-input
        //mention X
        //dic-> 0=space / 1=A / -8=B / -1=Z / -2=X
        for(int i=0;i<m;i++){//y
            for(int j=0;j<n;j++){//x
                if(mp[i][j]==-1){
                    for(int k=0;k<8;k++){
                        if(j+hx[k]>=0 && j+hx[k]<n && i+hy[k]>=0 && i+hy[k]<m){
                            if(mp[i+hy[k]][j+hx[k]]==0){
                                mp[i+hy[k]][j+hx[k]]=-2;
                            }
                        }
                    }
                }
            }
        }
        //-X
        //p
        int ans=0;
        while(!wait.empty()){
            int y=wait.front().first;
            int x=wait.front().second;
            wait.pop();
            for(int k=0;k<8;k++){
                if(x+px[k]>=0 && x+px[k]<n && y+py[k]>=0 && y+py[k]<m){
                    if(mp[y+py[k]][x+px[k]]==0){
                        mp[y+py[k]][x+px[k]]=mp[y][x]+1;
                        wait.push({y+py[k],x+px[k]});
                    }else if(mp[y+py[k]][x+px[k]]==-8){
                        ans=mp[y][x];
                    }
                }
            }
            if(ans){break;}
        }/*
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                write(mp[i][j]);
                putchar(' ');
            }
            putchar('\n');
        }*/
        if(ans){
            say("Minimal possible length of a trip is ");
            write(ans);
        }else{
            say("King Peter, you can't go now!");
        }
        putchar('\n');
    }
    return 0;
}
