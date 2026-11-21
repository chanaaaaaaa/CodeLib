#include <cstdio>
#include <vector>
#define int long long
using namespace std;

inline int read(){
	int x=0,c=0,w=1;
	while(c<'0' || c>'9'){
		c=getchar();
		if(c==-1){return 0;}
		if(c=='-'){w=-1;}
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*w;
}
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>=10){write(x/10);}
	putchar(x%10+'0');
}
//block
int N;
signed main(){
	N=read();
	vector<int>A(N+1),freq(N+1,0);
	for(int i=1;i<=N;++i){A[i]=read();}
	int res=1;
	for(int l=1;l<=N;){
		int r=l;
		while(r+1<=N && A[r+1]==A[l]){++r;}
		res+=(l-1)-freq[A[l]];
		freq[A[l]]+=(r-l+1);
		l=r+1;
	}
	write(res);
	putchar('\n');
	return 0;
}
