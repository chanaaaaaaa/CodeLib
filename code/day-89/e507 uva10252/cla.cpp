#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s1,s2;

    while(getline(cin,s1)){
        getline(cin,s2);

        vector<int>count1(26,0);
        vector<int>count2(26,0);

        for(char &c:s1) {
            if(c>='a' && c<='z'){
                ++count1[c-'a'];
            }
        }

        for(char &c:s2) {
            if(c>='a' && c<='z'){
                ++count2[c-'a'];
            }
        }

        string res = "";
        for(int i=0;i<26;++i){
            int common_count=min(count1[i],count2[i]);

            for(int k=0;k<common_count;++k){
                res+=(char)('a'+i);
            }
        }

        cout<<res<<'\n';
    }
    return 0;
}
