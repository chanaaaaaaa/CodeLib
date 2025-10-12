#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<utility>

using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0'&& c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
// -block
int N,cases=0;
vector<pair<int,int>>mp;
double dis[201][201],x,y;

inline void pts(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%.3lf ",dis[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

signed main(){

    while(N=read()){
        for(int i=0;i<N;i++){
            mp.push_back({read(),read()});
        }
        //do
        for(int i=0;i<N;i++){
            for(int j=0;j<i;j++){
                y=mp[i].first-mp[j].first;
                x=mp[i].second-mp[j].second;
                dis[i][j]=sqrt(x*x+y*y);
                dis[j][i]=dis[i][j];
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<N;k++){
                    pts();
                    double maxx;
                    if(dis[j][i]>dis[i][k]){
                        maxx=dis[j][i];
                    }else{
                        maxx=dis[i][k];
                    }
                    if(dis[j][k]>maxx){dis[j][k]=maxx;}
                }
            }
        }
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",++cases,dis[0][1]);
        //-do
        mp.clear();
    }
    return 0;
}
