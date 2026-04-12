#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")

#include<cstdio>
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
    while(true){
        int h1=read(),m1=read(),h2=read(),m2=read(),Ans;
        if(h1+m1+h2+m2==0){break;}

        if(h1>h2){
            if(m1>m2){
                Ans=60*(23-h1+h2)+(60+m2-m1);
            }else if(m1<m2){
                Ans=60*(24-h1+h2)+(m2-m1);
            }
        }else if(h1<h2){
            if(m1>m2){
                Ans=60*(h2-h1-1)+(60+m2-m1);
            }else{
                Ans=60*(h2-h1)+(m2-m1);
            }
        }else{
            if(m1>m2){
                Ans=(1440-m1+m2);
            }else{
                Ans=(m2-m1);
            }
        }

        write(Ans);
        putchar('\n');
    }
    return 0;
}
