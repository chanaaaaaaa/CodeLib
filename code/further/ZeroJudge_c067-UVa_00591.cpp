#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <iostream>
using namespace std;

int N,con=1;
int A[50];
int main(){


    while(cin>>N){
        if(N==0){break;}
        int tol=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            tol+=A[i];
        }
        tol/=N;
        int Ans=0;
        for(int i=0;i<N;i++){
            if(A[i]>tol){
                Ans+=A[i]-tol;
            }
        }
        cout<<"Set #"<<con<<"\n"<<"The minimum number of moves is "<<Ans<<"."<<"\n";
        con++;
    }
    return 0;
}

