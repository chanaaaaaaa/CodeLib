#include <cstdio>
#include <vector>
#include <algorithm>

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
inline void write(long long x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
struct Item{
    int c;
    long long v;
};
int N,M;
signed main(){
    while(N=read()){
        M=read();
        vector<Item>items(N);
        long long total_v=0;
        for(int i=0;i<N;++i){
            items[i].c=read();
            items[i].v=read();
            total_v+=items[i].v;
        }

        sort(items.begin(),items.end(),[](const Item &a,const Item &b){
            return a.c>b.c;
        });

        vector<long long>ans(M+1,0);
        for(int j=items[0].c;j<=M;++j){
            ans[j]=total_v;
        }

        vector<vector<long long>>dp(N+1,vector<long long>(M+1,-1));
        fill(dp[0].begin(),dp[0].end(),0);

        long long free_v=total_v;

        for(int p=0;p<N;++p){
            int cur_c=items[p].c;
            int nxt_c=0;
            if(p+1<N){nxt_c=items[p+1].c;}

            long long cur_v=items[p].v;

            free_v-=cur_v;

            for(int k=p;k>=0;--k){
                for(int w=0;w<=M;++w){
                    if(dp[k][w]!=-1){
                        dp[k+1][w]=max(dp[k+1][w],dp[k][w]+cur_v);
                    }
                }
            }

            for(int j=nxt_c;j<cur_c;++j){
                int diff=cur_c-j;
                long long best=0;
                for(int k=0;k<=p+1;++k){
                    int rem=M-k*diff;
                    if(rem<0){break;}
                    if(dp[k][rem]!=-1){
                        best=max(best,dp[k][rem]);
                    }
                }
                ans[j]=best+free_v;
            }

            int delta=cur_c-nxt_c;
            if(delta>0 && p+1<N){
                for(int k=1;k<=p+1;++k){
                    int shift=k*delta;
                    if(shift>M){
                        fill(dp[k].begin(),dp[k].end(),-1);
                    }else{
                        for(int w=M;w>=shift;--w){
                            dp[k][w]=dp[k][w-shift];
                        }
                        fill(dp[k].begin(),dp[k].begin()+shift,-1);
                    }
                }
            }
        }

        for(long long &res:ans){
            write(res);
            putchar('\n');
        }
    }
    return 0;
}
