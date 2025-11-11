#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>

#define MAXN 500
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
        if(x>=1000){break;}
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block

int mp[MAXN+1]={0};
inline void init(int a){
    for(int i=0;i<=a;++i){
        mp[i]=i;
    }
}
inline int fd(int a){
    return a==mp[a] ? a:mp[a]=fd(mp[a]);
}
inline bool un(int a,int b){
    if((a=fd(a))!=(b=fd(b))){
        mp[a]=b;
        return true;
    }else{
        return false;
    }
}

struct node{
    int start_point,
        end_point,
        weight;
    bool operator < (const node &a) const {return weight<a.weight;}
}E[MAXN*MAXN];

inline int normalize(int n1,int n2){
    int res=0;
    for(int i=0;i<4;++i){
        int a=n1%10, b=n2%10;

        if(a>b){swap(a,b);}
        res+=min(b-a,(a-b+10)%10);

        n1/=10;n2/=10;
    }
    return res;
}

signed main(){
    int T=read();
    while(T--){
        int N=read();
        vector<int>dat(N+1);
        for(int i=0;i<N;++i){
            dat[i]=read();
        }
        int cnt=-1;
        for(int i=0;i<N;++i){
            for(int j=i+1;j<N;++j){
                E[++cnt]={i,j,normalize(dat[i],dat[j])};
            }
        }
        sort(E,E+cnt+1);
        init(N);
        int res=0,tmp=INT_MAX;
        for(int i=0;i<=cnt;++i){
            if(un(E[i].start_point,E[i].end_point)){
                res+=E[i].weight;
            }
        }
        for(int i=0;i<N;++i){
            tmp=min(tmp,normalize(0,dat[i]));
        }
        write(res+tmp);
        putchar('\n');
    }
    return 0;
}

/*
4
2 1155 2211
3 1111 1155 5511
3 1234 5678 9090
4 2145 0213 9113 8113
*/
