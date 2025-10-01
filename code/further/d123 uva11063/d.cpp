#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N,Case=1;
    while(cin>>N){
        cout<<"Case #"<<Case<<": ";
        vector<int>dat;
        for(int i=0;i<N;i++){
            int temp;
            cin>>temp;
            dat.push_back(temp);
        }
        set<int>check;
        int flag=0;
        for(int i=0;i<N;i++){
            for(int j=i;j<N;j++){
                int temp=dat[i]+dat[j];
                if(check.count(temp)){
                    cout<<"It is not a B2-Sequence.\n\n";
                    flag=1;
                    break;
                }else{
                    check.insert(temp);
                }
                if(i==N-1 && j==N-1){
                    cout<<"It is a B2-Sequence.\n\n";
                }
            }
            if(flag){break;}
        }
        Case++;
    }
    return 0;
}
