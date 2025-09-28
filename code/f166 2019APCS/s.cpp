#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<vector>
#include<stdio.h>
//#define int long long
using namespace std;

int N,P,L,R,now,read=0;

signed main(){

    scanf("%d %d %d %d",&N,&P,&L,&R);
    int to[N];
    vector<int>st(N,-1);//0toN steps
    vector<int>wait={0};//next to execute
    st[0]=0;

    for(int i=0;i<N;i++){
        scanf("%d",&to[i]);
        if(to[i] >= N || to[i] < 0)to[i]=N;
    }
    int d[2]={-L,R};
    while(read<wait.size() && st[P]==-1){
        now=wait[read];
        read++;
        for(int i=0;i<2;i++){
            if(now+d[i]>=0 && now+d[i]<N){
                if(to[now+d[i]]<N){
                    if(st[to[now+d[i]]]==-1){
                        st[to[now+d[i]]]=st[now]+1;
                        wait.push_back(to[now+d[i]]);
                    }
                }
            }
        }
    }
    printf("%d\n",st[P]);
    return 0;
}
