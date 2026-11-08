#include <iostream>

#define int long long
using namespace std;

signed main(){
    int N;
    while(cin>>N){
        int num=0,res=0;
        while(true){
            int nxt=num*10+9;
            if(nxt<=N){
                num=nxt;
            }else{
                break;
            }
        }
        N-=num;
        while(N){
            res+=N%10;
            N/=10;
        }
        while(num){
            res+=num%10;
            num/=10;
        }
        cout<<res<<'\n';
    }
    return 0;
}
