#include<iostream>
#include<vector>
using namespace std;

vector<int>nxt;
inline void makenxt(string &give){
    nxt.assign(give.size(),0);
    for(int i=1,now=0;i<give.size();i++){
        while(now>0 && give[i]!=give[now]){
            now=nxt[now-1];
        }
        if(give[i]==give[now]){
            now++;
        }
        nxt[i]=now;
    }
}

inline void kmp(string &give,string &want){
    long long cnt=0;
    for(int i=0,now=0;i<give.size();i++){
        while(now>0 && give[i]!=want[now]){
            now=nxt[now-1];
        }
        if(give[i]==want[now]){now++;}
        if(now==want.size()){
            cnt++;
            now=nxt[now-1];
        }
    }
    cout<<cnt<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    string A,B;
    while(cin>>A>>B){
        makenxt(B);
        kmp(A,B);
        nxt.clear();
    }
    return 0;
}
