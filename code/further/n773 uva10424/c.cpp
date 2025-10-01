#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

signed main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    string A,B;
    while(getline(cin,A)){
        getline(cin,B);

        int a=0,b=0;
        for(int i=0;i<A.size();i++){
            if(A[i]>='a' && A[i]<='z'){
                a+=int(A[i]-'a')+1;
            }else if(A[i]>='A' && A[i]<='Z'){
                a+=int(A[i]-'A')+1;
            }
        }
        while(a>=10){
            int temp=0;
            while(a){
                temp+=a%10;
                a/=10;
            }
            a=temp;
        }
        for(int i=0;i<B.size();i++){
            if(B[i]>='a' && B[i]<='z'){
                b+=int(B[i]-'a')+1;
            }else if(B[i]>='A' && B[i]<='Z'){
                b+=int(B[i]-'A')+1;
            }
        }
        while(b>=10){
            int temp=0;
            while(b){
                temp+=b%10;
                b/=10;
            }
            b=temp;
        }
        double ans=(double)a/(double)b;
        if(ans>1){ans=1.0/ans;}
        cout<<fixed<<setprecision(2)<<ans*100<<" %\n";
    }
    return 0;
}
