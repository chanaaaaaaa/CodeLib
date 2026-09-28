#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAXN=2e5+5;

inline int min(const int &a,const int &b){
    return a<b?a:b;
}

inline void kmp_fail(const string &s,vector<int> &fail){
    int len=s.size();
    fail.assign(len,-1);
    int id=-1;
    for(int i=1;i<len;++i){
        while(~id && s[id+1]!=s[i]){
            id=fail[id];
        }
        if(s[id+1]==s[i]){
            ++id;
        }
        fail[i]=id;
    }
}
inline void kmp_match(const string &A,const string &B,vector<int> &fail,vector<int> &pos){
    int lenA=A.size(),lenB=B.size();
    pos.assign(lenA,0);
    int id=-1;
    for(int i=0;i<lenA;++i){
        while(~id && B[id+1]!=A[i]){
            id=fail[id];
        }
        if(B[id+1]==A[i]){
            ++id;
        }
        if(id==lenB-1){
            id=fail[id];
            pos[i]=1;
        }
    }
    return;
}

signed main(){
    int N,st,ed;
    string S,ans;
    while(cin>>N>>S>>ans){

        vector<int>FL;
        kmp_fail(ans,FL);
        vector<int>pos;
        kmp_match(S,ans,FL,pos);

        vector<int>pfx(S.size()+1,0);
        for(int i=0;i<S.size();++i){
            pfx[i+1]=pfx[i]+pos[i];
        }

        for(int i=0;i<N;++i){
            cin>>st>>ed;
            --st;--ed;
            st+=ans.size()-1;

            if(st<=ed && st<S.size()){
                ed=min(ed,S.size()-1);
                if(pfx[ed+1]-pfx[st] > 0){
                    cout<<"Yes\n";
                }else{
                    cout<<"No\n";
                }
            }else{
                cout<<"No\n";
            }
        }
        cout<<'\n';
    }
    return 0;
}
