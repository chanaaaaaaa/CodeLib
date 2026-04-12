#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>
#include <string>

using namespace std;

vector<pair<int,int>> ans;
vector<pair<int,int>> stu;

int N;

// Safe and properly initialized LCS function
inline int lcs() {
    vector<vector<int>>dp(N+1,vector<int>(N+1,0));
    
    for(int i=1;i<=N;++i) {
        for(int j=1;j<=N;++j){
            if(ans[i-1].second==stu[j-1].second){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }   
        }
    }
    return dp[N][N];
}

int main() {
    string S;
    bool restart=true;
    
    while(getline(cin, S)) {
        stringstream SS(S); 
        int tmp,pos;
        
        if(restart) {
            if(N==0) {
                SS >> N;
                getline(cin, S);
                SS.clear();
                SS.str(S);
            }
            
            ans.clear();
            pos=0;
            while(SS>>tmp){
                ans.push_back({tmp,++pos});
            }
            sort(ans.begin(),ans.end());
            restart=false;
            continue;
        }
        
        pos=0;
        stu.clear();
        while(SS>>tmp){
            stu.push_back({tmp,++pos});
        }
        
        if(stu.size()==1){
            restart=true;
            N=stu[0].first;
            continue;
        }
        
        sort(stu.begin(),stu.end());
        cout<<lcs()<<'\n';
    }
    return 0;
}