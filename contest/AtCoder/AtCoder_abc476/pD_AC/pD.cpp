#include <cstdio>
#include <vector>
#include <algorithm>

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
int N,M,K,X,Y;
vector<int>desserts;
vector<int>drinks;
signed main(){
    while(N=read()){
        M=read();K=read();
        X=read();Y=read();

        desserts.assign(N,0);
        for(int i=0;i<N;++i){desserts[i]=read();}
        drinks.assign(M,0);
        for(int i=0;i<M;++i){drinks[i]=read();}

        sort(desserts.begin(),desserts.end());
        sort(drinks.begin(),drinks.end());

        vector<int>Rdr(M,0);
        for(int i=0;i<M;++i){Rdr[i]=(drinks[i]-1)/K+1;}

        vector<int>Ac(N+1,0);
        for(int i=0;i<N;++i){Ac[i+1]=Ac[i]+desserts[i];}
        vector<int>Bc(M+1,0);
        for(int i=0;i<M;++i){Bc[i+1]=Bc[i]+drinks[i];}
        vector<int>RBc(M+1,0);
        for(int i=0;i<M;++i){RBc[i+1]=RBc[i]+Rdr[i];}

        int res=0;
        for(int i=M;i>=0;--i){
            if(RBc[i]>Y){continue;}

            int avaPr=X+Y*K-Bc[i];

            int pos=upper_bound(Ac.begin(),Ac.end(),avaPr)-Ac.begin()-1;
            if(pos<0){pos=0;}
            res=max(res,i+pos);
        }
        write(res);putchar('\n');
    }
    return 0;
}
