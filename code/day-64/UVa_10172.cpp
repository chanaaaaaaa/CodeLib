#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inilne")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-ferun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-function-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
//#include<iostream>
#include<cstdio>
//#include<stack>
#include<vector>
#include<queue>
#include<algorithm>

#define icc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return -1;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
vector<queue<int>>stations;
vector<int>bus;
int T,N,S,Q,cur,clock;
signed main(){
    int T=read();
    while(T--){
        N=read();S=read();Q=read();
        stations.clear();
        bus.clear();
        stations.assign(N,queue<int>());

        for(int i=0;i<N;++i){
            int C=read();
            while(C--){
                stations[i].push(read()-1);
            }
        }

        cur=0;clock=0;
        while(true){
			while(!bus.empty() && (bus.back()==cur || stations[cur].size()<Q)) {
				if(bus.back()!=cur){stations[cur].push(bus.back());}
				bus.pop_back();
				++clock;
			}
			while(!stations[cur].empty() && bus.size()<S) {
				bus.push_back(stations[cur].front());
				stations[cur].pop();
				++clock;
			}
			bool flag=true;
			for(int i=0;i<N;++i){
				if(!stations[i].empty() || !bus.empty()) {
					cur=++cur%N;
					clock+=2;
					flag=false;
					break;
				}
			}
			if(flag){break;}
		}

		write(clock);
		putchar('\n');
    }
	return 0;
}
/*
2
5 2 3
3 4 5 2
2 1 3
0
3 3 5 1
1 4
5 2 3
3 4 5 2
2 1 3
0
3 3 5 1
1 4
*/
