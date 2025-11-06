#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int N;
    cin>>N;
    cin.ignore();
    while(N--){
        string s;
        int cnt=0;
        for(int i=0;i<4;i++){
            cin>>s;
            for(int j=0;j<4;j++){
                int n=s[j]-'0';
                if(j%2==0){
                    if(n>=5){
                        cnt+=n*2-9;
                    }else{
                        cnt+=n*2;
                    }
                }else{
                    cnt+=n;
                }
            }
        }
        if(cnt%10==0){
            cout<<"Valid\n";
        }else{
            cout<<"Invalid\n";
        }
    }
    return 0;
}
