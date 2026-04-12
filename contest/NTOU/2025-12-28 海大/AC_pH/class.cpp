#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<cstdio>
#include<vector>
#include<algorithm>

#define int long long
using namespace std;

inline int read(){
    int x=0;char c=0;
    while(c<'0'||c>'9'){
        c=getchar();
        if(c==EOF||c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
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
const int MAXN=1000;

vector<int>primes;
bool isprime[MAXN+1];
inline void form(){
    for(int i=2;i<=MAXN;++i){
        if(!isprime[i]){primes.push_back(i);}
        for(int &p:primes){
            if(p*i>MAXN){break;}
            isprime[p*i]=true;
            if(i%p==0){break;}
        }
    }
}

vector<vector<int>>b_groups;
int b_cnt;

inline void backtrack(vector<int>&usg,int idx,vector<vector<int>>&groups,vector<int>&group_products,int m){
    if(idx==usg.size()){
        if(groups.size()<b_cnt){
            b_cnt=groups.size();
            b_groups=groups;
        }
        return;
    }

    if(groups.size()>=b_cnt){return;}

    int prime=usg[idx];

    for(int i=0;i<groups.size();++i){
        if(group_products[i]*prime<=m){
            groups[i].push_back(prime);
            group_products[i]*=prime;

            backtrack(usg,idx+1,groups,group_products,m);

            group_products[i]/=prime;
            groups[i].pop_back();
        }
    }

    groups.push_back({prime});
    group_products.push_back(prime);

    backtrack(usg,idx+1,groups,group_products,m);

    group_products.pop_back();
    groups.pop_back();
}

signed main(){
    form();
    int n,m;
    while((n=read())){
        m=read();
        vector<int>usg;
        auto max_pos=upper_bound(primes.begin(),primes.end(),n);
        usg.assign(primes.begin(),max_pos);

        sort(usg.begin(),usg.end(),greater<int>());
        vector<vector<int>>g_groups;
        vector<int>g_products;

        for(int prime:usg){
            int b_idx=-1;
            int b_remain=m+1;
            for(int i=0;i<g_groups.size();++i){
                if(g_products[i]*prime<=m){
                    int remaining=m-g_products[i]*prime;
                    if(remaining<b_remain){
                        b_remain=remaining;
                        b_idx=i;
                    }
                }
            }
            if(b_idx!=-1){
                g_groups[b_idx].push_back(prime);
                g_products[b_idx]*=prime;
            }else{
                g_groups.push_back({prime});
                g_products.push_back(prime);
            }
        }

        b_cnt=g_groups.size();
        b_groups=g_groups;

        vector<vector<int>>groups;
        vector<int>group_products;
        backtrack(usg,0,groups,group_products,m);

        write(b_groups.size());
        putchar('\n');
        for(auto &group:b_groups){
            write(group.size());
            putchar(' ');
            for(int i=group.size()-1;i>=0;--i){
                write(group[i]);
                if(i)putchar(' ');
            }
            putchar('\n');
        }
    }
    return 0;
}
