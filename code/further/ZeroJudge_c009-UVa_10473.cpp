#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    string A;
    while(cin>>A){
        if(A=="-1"){break;}
        if(A[0]=='0' && A[1]=='x'){
            unsigned long long Ans=0;
            for(int i=2;i<A.size();i++){
                if(int(A[i])>=65 && int(A[i])<=90){
                    Ans+=(int(A[i])-55)*pow(16,A.size()-1-i);
                }else{
                    Ans+=(int(A[i])-48)*pow(16,A.size()-1-i);
                }
            }
            cout<<Ans;
        }else{
            cout<<"0x";
            int temp=0;
            for(int i=0;i<A.size();i++){
                temp+=(int(A[A.size()-i-1])-48)*(pow(10,i));
            }
            int check=1;
            for(int i=8;i>=0;i--){
                int cls=floor(temp/pow(16,i));
                if(cls>=10){
                    check=0;
                    cout<<char(55+cls);
                    temp-=floor(temp/pow(16,i))*pow(16,i);
                }else if(cls>=1){
                    check=0;
                    cout<<char(48+cls);
                    temp-=floor(temp/pow(16,i))*pow(16,i);
                }
                else if(check==0){
                    cout<<"0";
                }

            }
        }
        cout<<"\n";
    }
    return 0;
}
