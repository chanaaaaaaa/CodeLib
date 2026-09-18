#include <iostream>
#include <map>

using namespace std;

string S;
int N,maxx;
map<char,int>mp;
signed main(){

    while(cin>>N){
        while(N--){
            mp.clear();
            maxx=0;
            cin>>S;
            for(char c:S){
                ++mp[c];
                maxx=max(maxx,mp[c]);
            }
            if(maxx*2>S.size()+1){
                cout<<"No\n";
            }else{
                string ans="";
                int prev=-1;
                while(true){
                    int idx=-1;
                    int val=0;
                    for(map<char,int>::iterator it=mp.begin();it!=mp.end();++it){
                        if(it->first-'a'==prev){continue;}
                        if(val<it->second){
                            val=it->second;
                            idx=it->first-'a';
                        }
                    }
                    if(idx==-1){
                        break;
                    }
                    ans+='a'+idx;
                    --mp['a'+idx];
                    prev=idx;
                }
                cout<<"Yes\n"<<ans<<'\n';
            }
        }
    }
    return 0;
}
