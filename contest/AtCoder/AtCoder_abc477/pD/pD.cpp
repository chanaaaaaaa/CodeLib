#include <cstdio>
#include <vector>

#define int long long
using namespace std;

inline int read(){
	int x=0,c=0;
	while(c<'0' || c>'9'){
		c=getchar();
		if(c==-1){return 0;}
		if(c>='a' && c<='z'){return c-'a';}
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
inline void write(int x){
	if(x>=10){write(x/10);}
	putchar(x%10+'0');
}
//block



signed main(){
    return 0;
}
