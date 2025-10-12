#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<string>
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return -1;}
    }
    while(c>='0'&& c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
// -block

char lib[2][5][4]={{{'*',' ',' ',' '},{' ',' ',' ',' '},{' ',' ','*',' '},{'*','*',' ',' '},{'*','*','*',' '}},
                   {{'*','*','*',' '},{'*','*','*','*'},{'*','*','*',' '},{'*','*',' ',' '},{' ','*',' ',' '}}};
int n,m,cnt,dat_cnt[5],dat[6],leng;

inline void write_str(int x,int y){
    for(int i=0;i<4;i++){
        putchar(lib[x][y][i]);
    }
    putchar('|');
}

inline void bfs(){
    if(leng==n){
        cnt++;
        for(int j=0;j<2;j++){
            for(int i=0;i<n;i++){
                write_str(j,dat[i]);
            }
            putchar('\n');
        }
        putchar('\n');
        putchar('\n');
        return;
    }
    for(int i=0;i<5;i++){
        if(!leng){
            dat[leng++]=i; dat_cnt[i]++;
            bfs();
            dat_cnt[i]--; leng--;
        }else if(dat_cnt[i]!=m && dat[leng-1]!=i){
            dat[leng++]=i; dat_cnt[i]++;
            bfs();
            dat_cnt[i]--; leng--;
        }
    }
}

signed main(void){
   while(n=read()){
        if(n==-1){break;}
        m=read();
        //if(n+m<=0){break;}
        cnt=0;
        bfs();
        putchar('S');
        putchar('u');
        putchar('m');
        putchar(' ');
        putchar(':');
        putchar(' ');
        write(cnt);
        putchar('\n');
   }
}
