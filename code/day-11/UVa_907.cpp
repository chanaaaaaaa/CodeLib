#include<cstdio>
#include<vector>
#include<algorithm>

#define ll long long
using namespace std;

inline long long read(){
    long long x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return -1;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(long long x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

inline bool check(ll mid,ll nights,vector<ll> dis){
	ll cnt=0,spend=0;
	for(auto &n:dis){
		if(n>mid)return false;
		if(cnt+n>mid){
			spend++;
			cnt=n;
		}else{cnt+=n;}
	}
	if(spend>nights){return false;}
	else{return true;}
}

inline int mid_dis(vector<ll> dis,ll nights){
	ll ans,l=0,r=*max_element(dis.begin(),dis.end());
	for(auto&c:dis){r+=c;}
	while(l<=r){
		ll mid=(r+l)/2;

		if(check(mid,nights,dis)){
			r=mid-1;
			ans=mid;
		}else{l=mid+1;}
	}
	return ans;
}
 main(){
    ll campsites,nights;

    while(campsites=read()+1){
        nights=read();
        vector<ll> dis;

        while(campsites--){dis.emplace_back(read());}
        write(mid_dis(dis,nights));
        putchar('\n');
    }
    return 0;
}
