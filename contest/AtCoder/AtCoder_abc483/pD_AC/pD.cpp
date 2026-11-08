#include <cstdio>
#include <vector>
#include <algorithm>
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
	while(N=read()){
		vector<int>A(N+1),S(N+1);
		S[0]=0;
		for(int i=1;i<=N;++i){
			A[i]=read();
			S[i]=S[i-1]+A[i];
		}

		vector<int> pre_max(N+1),pre_min(N+1),suf_max(N+1),suf_min(N+1);
		pre_max[0]=pre_min[0]=S[0];
		for(int i=1;i<=N;++i){
			pre_max[i]=max(pre_max[i-1],S[i]);
			pre_min[i]=min(pre_min[i-1],S[i]);
		}
		suf_max[N]=suf_min[N]=S[N];
		for(int i=N-1;i>=0;--i){
			suf_max[i]=max(suf_max[i+1],S[i]);
			suf_min[i]=min(suf_min[i+1],S[i]);
		}

		int res=pre_max[N]-pre_min[N]+1;
		for(int k=1;k<=N;++k){
			int Lmx=pre_max[k-1],Lmn=pre_min[k-1];
			int Rmx=suf_max[k]-2*A[k],Rmn=suf_min[k]-2*A[k];
			res=max(res,max(Lmx,Rmx)-min(Lmn,Rmn)+1);
		}
		write(res);
		putchar('\n');
	}
	return 0;
}
