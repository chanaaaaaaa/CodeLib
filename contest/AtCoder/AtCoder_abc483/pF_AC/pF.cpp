#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
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
	if(x>=10){write(x/10);}
	putchar(x%10+'0');
	return;
}
//block

const int XMAX=500000;
const int BLOCK=750;
vector<int>A,B,qs,delta,sub,ans;
vector<vector<int>>freq;
int N,sumA,Q,MX;
signed main(){
	N=read();
	A.assign(N,0);
	B.assign(N,0);
	sumA=0;

	for(int i=0;i<N;++i){
		A[i]=read();
		B[i]=read();
		sumA+=A[i];
	}

	Q=read();
	qs.assign(Q,0);

	MX=0;
	for(int i=0;i<Q;++i){
		qs[i]=read();
		if(qs[i]>MX){MX=qs[i];}
	}
    //-input

	delta.assign(MX+1,0);
	freq.assign(BLOCK+1,vector<int>());

	for(int i=0;i<N;++i){
		int a=A[i],b=B[i];
		if(b>BLOCK){
			for(int x=b-a;x<=MX;x+=b){
				delta[x]+=b;
			}
		}else{
			if(freq[b].empty()){
				freq[b].assign(b,0);
			}
			++freq[b][a];
		}
	}

	for(int m=1;m<=BLOCK;++m){
		if(freq[m].empty()){continue;}
		sub.assign(m,0);
		for(int a=0;a<m;++a){
			if(!freq[m][a]){continue;}
			sub[(m-a)%m]+=m*freq[m][a];
		}
		for(int r=0;r<m;++r){
			if(!sub[r]){continue;}
			int v=sub[r];
			for(int x=r;x<=MX;x+=m){
				if(x!=0){delta[x]+=v;}
			}
		}
	}

	ans.assign(MX+1,0);
	ans[0]=sumA;
	int cur=sumA;
	for(int x=1;x<=MX;++x){
		cur+=N;
		cur-=delta[x];
		ans[x]=cur;
	}

	for(int i=0;i<Q;++i){
		write(ans[qs[i]]);
		putchar('\n');
	}
	return 0;
}
