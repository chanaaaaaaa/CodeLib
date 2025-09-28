#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c!='X' && c!='J'){
        c=getchar();
	}
	if(c=='X'){return 0;}
	else if(c=='J'){return 1;}
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

int mp[501][501]={0};



signed main() { oioioi

    return 0;
}
/*
7 9
XXXXXJJJX
XXJJXXXJJ
XJJJXXXJX
XXXXXJJXJ
XJXXXJXXJ
JXXXXJXJJ
JJXXXXJJX
6 6
*/
