#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
//#include <utility>
using namespace std;

#define int long long

struct Pt{
	int x,y;
};

inline int cross(const Pt&a, const Pt&b){
	return a.x*b.y-a.y*b.x;
}

inline bool half(const Pt&p){
	return p.y>0 || (p.y==0 && p.x>0);
}

inline bool cmp(const Pt&a, const Pt&b){
	bool ha=half(a),hb=half(b);

	if(ha!=hb){return ha>hb;}
	return cross(a,b)>0;
}

signed main(){
	int T,N;
	while(cin>>T){
		while(T--){
			cin>>N;
			vector<Pt>p(N);

			for(int i=0;i<N;++i){
				cin>>p[i].x>>p[i].y;
			}

			sort(p.begin(),p.end(),cmp);
			p.insert(p.end(),p.begin(),p.end());

			int res=0,Rs=0;
			for(int Ls=0;Ls<N;++Ls){
				if(Rs<Ls){Rs=Ls;}
				while(Rs+1<Ls+N && cross(p[Ls],p[Rs+1])>0){
					++Rs;
				}
				res=max(res,Rs-Ls+1);
			}
			cout<<res<<'\n';
		}
	}
	return 0;
}
