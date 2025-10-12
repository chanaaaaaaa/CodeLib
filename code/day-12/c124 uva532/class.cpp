#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<queue>
#include<utility>
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
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

inline int read_char(){//S->1 End->-8 #->-1 .->0; if negative cant go
    char c=0;
    while(c!='S' && c!='E' && c!='#' && c!='.'){
        c=getchar();
    }
    if(c=='S'){
        return 1;
    }if(c=='E'){
        return -8;
    }if(c=='#'){
        return -1;
    }if(c=='.'){
        return 0;
    }
}

signed main(){
    int L,R,C;
    while(L=read(),R=read(),C=read()){
        if(L+R+C==0){break;}
        //init&&input
        queue<pair<pair<int,int>,int>>wait;
        int mp[L][R][C];
        for(int i=0;i<L;i++){
            for(int j=0;j<R;j++){
                for(int k=0;k<C;k++){
                    int temp=read_char();
                    if(temp==1){wait.push({{i,j},k});temp--;}
                    mp[i][j][k]=temp;
                }
            }
        }
        //-init&input
        //bfs
        int flag=0;
        while(!wait.empty()){
            int x=wait.front().first.first;
            int y=wait.front().first.second;
            int z=wait.front().second;
            wait.pop();
            for(int f=0;f<6;f++){
                if(x+dx[f]>=0 && x+dx[f]<L && y+dy[f]>=0 && y+dy[f]<R && z+dz[f]>=0 && z+dz[f]<C){
                    if(mp[x+dx[f]][y+dy[f]][z+dz[f]]==0){
                        mp[x+dx[f]][y+dy[f]][z+dz[f]]=mp[x][y][z]+1;
                        wait.push({{x+dx[f],y+dy[f]},z+dz[f]});
                    }else if(mp[x+dx[f]][y+dy[f]][z+dz[f]]==-8){
                        flag=mp[x][y][z]+1;
                    }
                }
                if(flag){break;}
            }
            if(flag){break;}
        }
        //-bfs
        //output
        if(flag){
            putchar('E');
            putchar('s');
            putchar('c');
            putchar('a');
            putchar('p');
            putchar('e');
            putchar('d');
            putchar(' ');
            putchar('i');
            putchar('n');
            putchar(' ');
            write(flag);
            putchar(' ');
            putchar('m');
            putchar('i');
            putchar('n');
            putchar('u');
            putchar('t');
            putchar('e');
            putchar('(');
            putchar('s');
            putchar(')');
            putchar('.');
        }else{
            putchar('T');
            putchar('r');
            putchar('a');
            putchar('p');
            putchar('p');
            putchar('e');
            putchar('d');
            putchar('!');
        }
        putchar('\n');
    }
    return 0;
}
