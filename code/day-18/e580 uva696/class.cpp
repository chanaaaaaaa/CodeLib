#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
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
vector<vector<bool>>mp(99,vector<bool>(99));
queue<pair<int,int>>wt;
int dx[4]={1,-1,0,0},
    dy[4]={0,0,1,-1},
    y,x,nx,my,mx,cnt,N;
bool check;
signed main(void){
    N=read();
    getchar();
    while(N--){
        y=read()-1,x=read()-1,nx=0,my=0,mx=0,cnt=0;
        check=false;
        while(true){
            int t=getchar();
            if(t=='1'){
                mp[my][nx++]=true;
                if(check){check=false;}
            }else if(t=='0'){
                mp[my][nx++]=false;
                if(check){check=false;}
            }else{
                if(!check){
                    check=true;
                    if(!mx){mx=nx;}
                    my++;
                    nx=0;
                }else{break;}
            }
        }
        if(!mp[y][x]){
            wt.push({y,x});
            mp[y][x]=true;
            cnt++;
        }
        while(!wt.empty()){
            x=wt.front().second;
            y=wt.front().first;
            wt.pop();
            for(int f=0;f<4;f++){
                if(y+dy[f]>=0 && y+dy[f]<my && x+dx[f]>=0 && x+dx[f]<mx){
                    if(!mp[y+dy[f]][x+dx[f]]){
                        wt.push({y+dy[f],x+dx[f]});
                        mp[y+dy[f]][x+dx[f]]=true;
                        cnt++;
                    }
                }
            }
        }
        write(cnt);
        putchar('\n');
        if(N){putchar('\n');}//if judge uva need this
    }                        //no use this 1ms
}                            //use this 2ms
