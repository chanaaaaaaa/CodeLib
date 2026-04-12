#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    while(cin>>N){
        cout<<N<<" is ";
        for(int i=2;i<ceil(sqrt(N))+1;i++){
            if(N%i==0){
                cout<<"not prime."<<"\n";
                break;
            }else if(i==ceil(sqrt(N))){
                int maxx=0,rN=0;
                for(;maxx<6;maxx++){
                    if(pow(10,maxx)>N){
                        break;
                    }
                }
                maxx--;
                int DN=N;
                for(int j=0;j<=maxx;j++){
                    int temp=DN/pow(10,j);
                    DN-=(temp%10)*pow(10,j);
                    rN+=(temp%10)*pow(10,maxx-j);
                }
                if(rN==N){cout<<"prime."<<"\n";break;}
                for(int j=2;j<ceil(sqrt(rN))+1;j++){
                    if(rN%j==0){
                        cout<<"prime."<<"\n";
                        break;
                    }else if(j==ceil(sqrt(rN))){
                        cout<<"emirp."<<"\n";
                        break;
                    }
                }
                break;
            }
        }
    }
    return 0;
}
