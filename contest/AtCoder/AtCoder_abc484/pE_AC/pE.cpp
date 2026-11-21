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
int N,L,R;
struct BIT{
	int n;
	vector<int>t;
	BIT(int n=0):n(n),t(n+1,0){}
	void add(int i,int v){
		for(;i<=n;i+=i&-i){t[i]+=v;}
	}
	int sum(int i){
		int s=0;
		for(;i>0;i-=i&-i){s+=t[i];}
		return s;
	}
	int range(int l,int r){
		if(l>r){return 0;}
		return sum(r)-sum(l-1);
	}
};

signed main(){
	N=read(),L=read(),R=read();
	vector<int>S(N+1);
	S[0]=0;
	for(int i=1;i<=N;++i){
		S[i]=S[i-1]+read();
	}

	vector<int>vals=S;
	sort(vals.begin(),vals.end());
	vals.erase(unique(vals.begin(),vals.end()),vals.end());

	auto idx=[&](int x)->int{
		return lower_bound(vals.begin(),vals.end(),x)-vals.begin()+1;
	};

	BIT bit(vals.size());
	int res=0;
	bit.add(idx(S[0]),1);
	for(int r=1;r<=N;++r){
		int left=lower_bound(vals.begin(),vals.end(),S[r]-R)-vals.begin()+1;
		int right=upper_bound(vals.begin(),vals.end(),S[r]-L)-vals.begin();
		res+=bit.range(left,right);
		bit.add(idx(S[r]),1);
	}
	write(res);
	putchar('\n');
	return 0;
}
