#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<memory.h>
#include<algorithm>

#define int long long
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block

signed main(){
    int T=read();
    for(int cases=1;cases<=T;++cases){
        int N=read(),M=read(),K=read();
        int lib[N+1][M+1];
        int dat[N+1][M+1];

        memset(dat,0,sizeof(dat));

        for(int i=1;i<=N;++i){
            for(int j=1;j<=M;++j){
                lib[i][j]=read();
            }
        }
        for(int i=1;i<=N;++i){
            for(int j=1;j<=M;++j){
                dat[i][j]=dat[i-1][j]+dat[i][j-1]+lib[i][j]-dat[i-1][j-1];
            }
        }
        //-2D primix sum && init
        //search
        int max_size=0,min_prc=0;
        for(int si=1;si<=N;++si){//start-i
            for(int sj=1;sj<=M;++sj){//start-j
                for(int ei=si;ei<=N;++ei){//end-i
                    for(int ej=sj;ej<=M;++ej){//end-j
                        int room_cnt=(ei-si+1)*(ej-sj+1);
                        int room_prc=dat[ei][ej]+dat[si-1][sj-1]-dat[si-1][ej]-dat[ei][sj-1];

                        if(room_prc<=K){
                            if(room_cnt>max_size){
                                max_size=room_cnt;
                                min_prc=room_prc;
                                /*
                                write(si);putchar('-');
                                write(sj);putchar('-');
                                write(ei);putchar('-');
                                write(ej);putchar('=');
                                write(max_size);putchar('-');
                                write(min_prc);putchar('\n');
                                */
                            }else if(room_cnt==max_size){
                                min_prc=min(min_prc,room_prc);
                                /*
                                write(si);putchar('-');
                                write(sj);putchar('-');
                                write(ei);putchar('-');
                                write(ej);putchar('=');
                                write(max_size);putchar('-');
                                write(min_prc);putchar('\n');
                                */
                            }
                        }
                    }
                }
            }
        }
        putchar('C');putchar('a');putchar('s');putchar('e');putchar(' ');putchar('#');
        write(cases);putchar(':');putchar(' ');
        write(max_size);putchar(' ');
        write(min_prc);
        putchar('\n');
    }
    return 0;
}
/*
1
5 6 15
10 1 10 20 10 10
30 1 1 5 1 1
50 1 1 20 1 1
10 5 5 10 5 1
40 10 90 1 10 10
*/
