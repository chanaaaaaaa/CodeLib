#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
//#include<functional>

#define s second
#define f first
#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main(){
    int n,k,c;
    while(n=read()){
        k=read();c=read();
        vector<pair<int,pair<int,int>>>traf(n);
        for(int i=0;i<n;++i){
            traf[i].first=read();
        }
        for(int i=0;i<n;++i){
            traf[i].second.first=read();
        }
        for(int i=0;i<n;++i){
            traf[i].second.second=read();
        }
        sort(traf.begin(),traf.end());


        vector<vector<int>>dp(n+1,vector<int>(k+1,1e18));
        dp[0][0]=0;

        int pos=0;
        for(int i=0;i<n;++i){
            int p=traf[i].first,
                g=traf[i].second.first,
                r=traf[i].second.second;

            int walk_time=p-pos;
            pos=p;

            for(int j=0;j<=k;++j){
                if(dp[i][j]==1e18){continue;}

                int time=dp[i][j]+walk_time,
                    cycle=g+r,
                    mod=time%cycle,
                    wait_time=0;
                if(mod>=g){
                    wait_time=cycle-mod;
                }
                dp[i+1][j]=min(dp[i+1][j],time+wait_time);

                if(j<k){
                    dp[i+1][j+1]=min(dp[i+1][j+1],time);
                }
            }
        }

        int walk_to_school=c-pos;
        int ans=1e18;
        for(int j=0;j<=k;++j){
            if(dp[n][j]!=1e18){
                ans=min(ans,dp[n][j]+walk_to_school);
            }
        }

        write(ans);
        putchar('\n');
    }
    return 0;
}
