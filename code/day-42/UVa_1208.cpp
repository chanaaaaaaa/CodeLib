#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<algorithm>

#define MAXN 26
#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block

struct node{
    int start_point,
        end_point,
        weight;
}E[MAXN*MAXN];

int mp[MAXN+1]={0},tcnt=0;
inline void init(int a){
    for(int i=0;i<=a;++i){
        mp[i]=i;
    }
    tcnt=a;
}
inline int fd(int a){
    return a==mp[a] ? a:mp[a]=fd(mp[a]);
}
inline bool un(int a,int b){
    if((a=fd(a))!=(b=fd(b))){
        mp[a]=b;--tcnt;
        return true;
    }else{
        return false;
    }
}
bool cmp(node a,node b){
    return a.weight < b.weight;
}
signed main(){
    int T=read();
    for(int cases=1;cases<=T;++cases){
        int N=read();
        init(N);

        int cnt=0;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                int w=read();
                if(j>i && w!=0){
                    E[cnt].start_point=i;
                    E[cnt].end_point=j;
                    E[cnt++].weight=w;
                }
            }
        }
        sort(E,E+cnt,cmp);
        putchar('C');putchar('a');putchar('s');putchar('e');putchar(' ');write(cases);putchar(':');putchar('\n');
        for(int i=0;i<cnt;++i){
            if(un(E[i].start_point,E[i].end_point)){
                putchar('A'+E[i].start_point);
                putchar('-');
                putchar('A'+E[i].end_point);
                putchar(' ');
                write(E[i].weight);
                putchar('\n');
            }
            if(tcnt==1){break;}
        }
    }
    return 0;
}

/*
1
6
0, 8, 12, 0, 0, 7
8, 0, 0, 3, 0, 0
12, 0, 0, 0, 6, 0
0, 3, 0, 0, 0, 4
0, 0, 6, 0, 0, 5
7, 0, 0, 4, 5, 0
*/
