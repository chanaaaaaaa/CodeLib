#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int MAXN = 105;
vector<int> primes;
bool is_composite[MAXN] = {false}; 

int main() {
    for(int i=2;i<MAXN;++i){
        if(!is_composite[i]){
            primes.push_back(i);
        }
        for(int &n:primes){
            if(n*i>=MAXN){break;}
            is_composite[n*i]=true;
            if(i%n==0){break;}
        }
    }   
    
    vector<vector<int>>ans(101,vector<int>());
    ans[2].push_back(1);
    
    for(int i=3;i<=100;++i){
        ans[i]=ans[i-1]; 
        int tmp=i;
        
        for(int j=0;j<primes.size() && tmp!=1;++j){
            int cnt=0;
            while(tmp%primes[j]==0){
                ++cnt;
                tmp/=primes[j];
            }
            
            if(j<ans[i].size()){
                ans[i][j]+=cnt;
            }else{
                ans[i].push_back(cnt);
            }
        }
    }
    
    int N;
    while(cin>>N && N!=0){
        cout<<setw(3)<<N<<"! =";
        
        int cnt=0;
        for(int &n:ans[N]){
            ++cnt;
            if(cnt==16){
                cout<<"\n      ";
            }
            cout<<setw(3)<<n;
        }
        cout<<'\n';
    }
    
    return 0;
}