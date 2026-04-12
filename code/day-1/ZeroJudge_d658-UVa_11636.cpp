//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")

#include<cstdio>
#include<math.h>

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
inline void write(long x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main() {
    int cases=1;
    while(true){
        int in=read();
        if(in<0){break;}

        putchar('C');
        putchar('a');
        putchar('s');
        putchar('e');
        putchar(' ');
        write(cases++);
        putchar(':');
        putchar(' ');

        //


        write(ceil(log(in)/M_LN2));
        //
        putchar('\n');
    }
    return 0;
}
