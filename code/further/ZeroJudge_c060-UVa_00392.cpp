#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int A[9];
    int nz=-1;
    while(cin>>A[8]){
        if(A[8]!=0){nz=8;}
        for(int i=7;i>=0;i--){
            cin>>A[i];
            if(A[i]!=0 && nz==-1){nz=i;}
            else if(i==0 && nz==-1){nz=i;}
        }
        for(int i=nz;i>=0;i--){
            if(i!=nz){//if first num?
                if(A[i]!=0){
                    if(A[i]>0){
                        cout<<" + ";
                    }else{
                        cout<<" - ";
                    }
                }
            }else{
                if(A[i]<0){
                    cout<<"-";
                }
            }
            if(i!=nz){
                if(A[i]!=0){
                    if(A[i]>0){
                        if(A[i]!=1 || i==0){
                            cout<<A[i];
                        }
                    }else{
                        if(A[i]!=-1 || i==0){
                            cout<<-A[i];
                        }
                    }
                }
            }else{
                if(A[i]>0){
                    if(A[i]!=1){
                        cout<<A[i];
                    }
                }else{
                    if(A[i]!=-1){
                        cout<<-A[i];
                    }
                }/*
                if(nz==0 && A[i]==0){
                    cout<<"0";
                }*/
            }
            if(A[i]!=0){
                if(i==1){
                    cout<<"x";
                }else if(i>1){
                    cout<<"x^"<<i;
                }
            }
        }
        cout<<"\n";
        nz=-1;
    }

    return 0;
}
