#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")

#include<cstdio>
#include<algorithm>
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
	}
	while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
	}
	return x*w;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

int LCS[101][101],a[101],b[101],as,bs;
signed main() {
    int cases=1;
    while(true){
        as=read();
        bs=read();
        for(int i=1;i<=as;i++){a[i]=read();}
        for(int i=1;i<=bs;i++){b[i]=read();}

        if(as+bs==0){break;}

        for(int i=1;i<=as;i++){
            for(int j=1;j<=bs;j++){
                if(a[i]==b[j]){LCS[i][j]=LCS[i-1][j-1]+1;}
                else{LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);}
            }
        }

        putchar('T');putchar('w');putchar('i');putchar('n');putchar(' ');putchar('T');putchar('o');putchar('w');putchar('e');putchar('r');putchar('s');putchar(' ');putchar('#');
        write(cases++);
        putchar('\n');

        putchar('N');putchar('u');putchar('m');putchar('b');putchar('e');putchar('r');putchar(' ');putchar('o');putchar('f');putchar(' ');putchar('T');putchar('i');putchar('l');putchar('e');putchar('s');putchar(' ');putchar(':');putchar(' ');
        write(LCS[as][bs]);
        putchar('\n');putchar('\n');
    }
    return 0;
}
