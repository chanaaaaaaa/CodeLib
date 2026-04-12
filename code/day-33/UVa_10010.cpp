//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//--block
int T,N,M,K,
    dx[8]={1,-1,0,0,1,1,-1,-1},
    dy[8]={0,0,1,-1,1,-1,1,-1};
string in;
vector<string>mp(50);
inline bool check(int r,int l,int f){
    for(int i=1;i<in.size();i++){
        l+=dx[f];
        r+=dy[f];
        if(l<0 || r<0 || l>=M || r>=N){return false;}
        if(mp[r][l]>='a' && mp[r][l]<='z'){
            if(in[i]>='a' && in[i]<='z'){
                if(mp[r][l]!=in[i]){return false;}
            }else if(in[i]>='A' && in[i]<='Z'){
                if(mp[r][l]!=in[i]-'A'+'a'){return false;}
            }else{return false;}
        }else if(mp[r][l]>='A' && mp[r][l]<='Z'){
            if(in[i]>='a' && in[i]<='z'){
                if(mp[r][l]!=in[i]-'a'+'A'){return false;}
            }else if(in[i]>='A' && in[i]<='Z'){
                if(mp[r][l]!=in[i]){return false;}
            }else{return false;}
        }else{return false;}
    }
    return true;
}

inline void solve(){
    for(int j=0;j<M;j++){
        for(int i=0;i<N;i++){
            if(mp[i][j]==in[0] || mp[i][j]==in[0]-'a'+'A' || mp[i][j]==in[0]-'A'+'a'){
                for(int f=0;f<8;f++){
                    if(check(i,j,f)){
                        cout<<i+1<<' '<<j+1<<"\n";
                        return;
                    }
                }
            }
        }
    }
    cout<<"-1\n";
    return;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin.ignore();
        cin>>N>>M;

        for(int i=0;i<N;i++){
            cin>>mp[i];
        }
        cin>>K;
        while(K--){
            cin>>in;
            solve();
        }
        if(T)cout<<'\n';
    }
    return 0;
}
/*
1

8 11
abcDEFGhigg
hEbkWalDork
FtyAwaldORm
FtsimrLqsrc
byoArBeDeyv
Klcbqwikomk
strEBGadhrb
yUiqlxcnBjf
4
Waldorf
Bambi
Betty
Dagbert
*/
