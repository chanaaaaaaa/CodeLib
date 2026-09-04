#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

signed main(){
    int T,cnt,sz;
    string S;

    cin>>T;
    cin.ignore();
    cin.ignore();
    while(T--){
        cnt=0;sz=0;
        vector<string>dic;
        unordered_map<string,int>mp;

        while(true){
            getline(cin,S);
            if(S==""){break;}
            ++cnt;
            sz+=S.size();
            if(!dic.empty()){
                for(string &s1:dic){
                    ++mp[s1+S];
                    ++mp[S+s1];
                }
            }
            dic.push_back(S);
        }
        for(auto it:mp){
            //cout<<it.first<<' '<<it.second<<'\n';
            if(it.second>=cnt/2 && it.first.size()==sz*2/cnt){
                cout<<it.first<<'\n';
                break;
            }
        }
        if(T){cout<<'\n';}
    }
    return 0;
}
