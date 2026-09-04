#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

#define int long long
using namespace std;

inline int read(){
    int x=0,c=0,w=1;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}
//==
struct elephant{
    int id;
    int wgt;
    int iq;
};

inline bool cmp(const elephant &a,const elephant &b){
    if(a.wgt==b.wgt){
        return a.iq>b.iq;
    }
    return a.wgt<b.wgt;
}

vector<elephant>dat;
signed main(){
    int w,q,idx=1;
    while(w=read()){
        q=read();
        dat.push_back({idx++,w,q});
    }
    int sz=dat.size();
    if(sz==0){return 0;}

    sort(dat.begin(),dat.end(),cmp);

    int maxx=0;
    int endp=-1;

    vector<int>dp(sz,1);
    vector<int>pre(sz,-1);

    for(int i=0;i<sz;++i){
        for(int j=0;j<i;++j){
            if(dat[i].wgt>dat[j].wgt && dat[i].iq<dat[j].iq){
                if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    pre[i]=j;
                }
            }
        }
        if(dp[i]>maxx){
            maxx=dp[i];
            endp=i;
        }
    }

    vector<int>res;
    while(endp!=-1){
        res.push_back(dat[endp].id);
        endp=pre[endp];
    }
    write(maxx);
    for(int i=res.size()-1;i>=0;--i){
        putchar('\n');
        write(res[i]);
    }
    putchar('\n');

    return 0;
}
