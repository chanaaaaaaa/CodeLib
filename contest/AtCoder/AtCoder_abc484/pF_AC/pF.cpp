#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <cstdio>
#include <vector>

#define int long long
using namespace std;

inline int read(){
	int x=0,c=0,s=1;
	while(c<'0' || c>'9'){
		if(c=='-'){s=-1;}
		c=getchar();
		if(c==-1){return 0;}
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*s;
}

const int INF=1000000007;
vector<int>mn,mx;
int qmn,qmx;

inline void apply(int p,int x){
	if(x<0){
		mn[p]=INF;
		mx[p]=0;
	}else{
		mn[p]=x;
		mx[p]=x;
	}
}
inline void pull(int p){
	mn[p]=mn[p<<1]<mn[p<<1|1]?mn[p<<1]:mn[p<<1|1];
	mx[p]=mx[p<<1]>mx[p<<1|1]?mx[p<<1]:mx[p<<1|1];
}
void build(int p,int l,int r){
	if(l==r){
		apply(p,read());
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pull(p);
}
void upd(int p,int l,int r,int i,int x){
	if(l==r){
		apply(p,x);
		return;
	}
	int mid=(l+r)>>1;
	if(i<=mid){upd(p<<1,l,mid,i,x);}
	else{upd(p<<1|1,mid+1,r,i,x);}
	pull(p);
}
void qry(int p,int l,int r,int ql,int qr){
	if(ql<=l && r<=qr){
		if(mn[p]<qmn){qmn=mn[p];}
		if(mx[p]>qmx){qmx=mx[p];}
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid){qry(p<<1,l,mid,ql,qr);}
	if(qr>mid){qry(p<<1|1,mid+1,r,ql,qr);}
}
signed main(){
	int N=read(),Q=read();
	mn.assign(4*N+5,INF);
	mx.assign(4*N+5,0);
	build(1,1,N);
	for(int qi=0;qi<Q;++qi){
		int t=read();
		if(t==1){
			int i=read(),x=read();
			upd(1,1,N,i,x);
		}else{
			int l=read(),r=read();
			qmn=INF;
			qmx=0;
			qry(1,1,N,l,r);
			if(qmn==INF || qmn==qmx){puts("Yes");}
			else{puts("No");}
		}
	}
	return 0;
}
