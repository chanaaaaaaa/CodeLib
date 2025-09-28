#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin>>n;
    while(n--){
        int N,b1=0,b2=0;
        cin>>N;
        int N_c=N;
        for(int i=13;i>=0;i--){
            if(N>=pow(2,i)){
                N-=pow(2,i);
                b1++;
            }
        }
        for(int i=5;i>=0;i--){
            if(N_c>=pow(10,i)){
                int temp=N_c/pow(10,i);
                if(temp==7) b2+=3;
                else if(temp==1 || temp==2 || temp==4 || temp==8) b2+=1;
                else b2+=2;
                N_c-=temp*pow(10,i);
            }
        }
        cout<<b1<<" "<<b2<<"\n";
    }
    return 0;
}
