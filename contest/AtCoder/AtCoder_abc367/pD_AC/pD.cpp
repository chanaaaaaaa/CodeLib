#include <cstdio>
#include <vector>

#define int long long
using namespace std;

inline int read(){
	int x=0,c=0;
	while(c<'0' || c>'9'){
		c=getchar();
		if(c==-1){return 0;}
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>=10){write(x/10);}
	putchar(x%10+'0');
}
//block
int N,M,ans;
vector<int>a,b;
signed main(){
	while(N=read()){
		M=read();
		a.assign(N,0);
		for(int i=0;i<N;++i){
			a[i]=read();
		}
		int tp=0;
		b.assign(M,0);
		for(int i=0;i<N;++i){
			tp=(tp+a[i])%M;
			++b[tp];
		}
		
		int t=tp;
		int ans=0;
		for(int i=0;i<N;++i){
			tp=(tp+a[i])%M;
			++b[tp];
			--b[(tp-t+M)%M];
			ans+=b[tp]-1;
		}
		
		write(ans);
		putchar('\n');
	}
	return 0;
}