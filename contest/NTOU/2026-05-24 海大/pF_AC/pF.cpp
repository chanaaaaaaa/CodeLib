#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;

int cnt[26];
int need[5][26];

inline void init(){
    memset(need,0,sizeof(need));
    // apple
    need[0]['a'-'a']=1;need[0]['p'-'a']=2;need[0]['l'-'a']=1;need[0]['e'-'a']=1;
    // guava
    need[1]['g'-'a']=1;need[1]['u'-'a']=1;need[1]['a'-'a']=2;need[1]['v'-'a']=1;
    // peach
    need[2]['p'-'a']=1;need[2]['e'-'a']=1;need[2]['a'-'a']=1;need[2]['c'-'a']=1;need[2]['h'-'a']=1;
    // mango
    need[3]['m'-'a']=1;need[3]['a'-'a']=1;need[3]['n'-'a']=1;need[3]['g'-'a']=1;need[3]['o'-'a']=1;
    // lemon
    need[4]['l'-'a']=1;need[4]['e'-'a']=1;need[4]['m'-'a']=1;need[4]['o'-'a']=1;need[4]['n'-'a']=1;
}

inline int upper_bound(int f){
    int res=100;
    for(int i=0;i<26;++i){
        if(need[f][i]){
            res=min(res,cnt[i]/need[f][i]);
        }
    }
    return res;
}

inline bool valid(int take[5]){
    int use[26]={0};
    for(int f=0;f<5;++f){
        for(int i=0;i<26;++i){
            use[i]+=need[f][i]*take[f];
        }
    }
    for(int i=0;i<26;++i){
        if(use[i]>cnt[i]){return false;}
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();

    string S;
    while(cin>>S){
        memset(cnt,0,sizeof(cnt));
        for(char &c:S){++cnt[c-'a'];}

        int lim[5];
        for(int f=0;f<5;++f){lim[f]=upper_bound(f);}

        int ans=0;
        int take[5];
        for(take[0]=0;take[0]<=lim[0];++take[0])
        for(take[1]=0;take[1]<=lim[1];++take[1])
        for(take[2]=0;take[2]<=lim[2];++take[2])
        for(take[3]=0;take[3]<=lim[3];++take[3])
        for(take[4]=0;take[4]<=lim[4];++take[4])
            if(valid(take))
                ans=max(ans,take[0]+take[1]+take[2]+take[3]+take[4]);

        cout<<ans<<'\n';
    }
    return 0;
}