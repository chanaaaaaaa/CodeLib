#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")

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
        int al=read();
        if(al<0){break;}
        //
        int add[12],de[12];

        for(int i=0;i<12;i++){
            add[i]=read();
        }
        for(int i=0;i<12;i++){
            de[i]=read();
        }
        putchar('C');
        putchar('a');
        putchar('s');
        putchar('e');
        putchar(' ');
        write(cases++);
        putchar(':');
        putchar('\n');
        for(int i=0;i<12;i++){
            putchar('N');
            putchar('o');
            putchar(' ');
            putchar('p');
            putchar('r');
            putchar('o');
            putchar('b');
            putchar('l');
            putchar('e');
            putchar('m');
            if(al>=de[i]){
                al-=de[i];
                putchar('!');
                putchar(' ');
                putchar(':');
                putchar('D');
            }else{
                putchar('.');
                putchar(' ');
                putchar(':');
                putchar('(');
            }
            al+=add[i];
            putchar('\n');
        }
    }
    return 0;
}
