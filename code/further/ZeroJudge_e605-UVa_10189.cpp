#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int n,m,ron=1;
int bom[100][100];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);


    while(cin>>n>>m){
        if(n+m==0){break;}
        //part-input
        char A;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>A;
                if(A=='*'){bom[i][j]=9;}
                else{bom[i][j]=0;}
            }
        }
        //part-doing
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(bom[i][j]>=9){
                    if(i==0){
                        if(j==0){
                            bom[0][1]++;
                            bom[1][0]++;
                            bom[1][1]++;
                        }else if(j==m-1){
                            bom[0][j-1]++;
                            bom[1][j-1]++;
                            bom[1][j]++;
                        }else{
                            bom[0][j-1]++;
                            bom[0][j+1]++;
                            bom[1][j-1]++;
                            bom[1][j+1]++;
                            bom[1][j]++;
                        }
                    }else if(i==n-1){
                        if(j==0){
                            bom[i-1][0]++;
                            bom[i-1][1]++;
                            bom[i][1]++;
                        }else if(j==m-1){
                            bom[i-1][j]++;
                            bom[i-1][j-1]++;
                            bom[i][j-1]++;
                        }else{
                            bom[i][j+1]++;
                            bom[i][j-1]++;
                            bom[i-1][j+1]++;
                            bom[i-1][j-1]++;
                            bom[i-1][j]++;
                        }
                    }else if(j==0){
                        bom[i+1][j]++;
                        bom[i-1][j]++;
                        bom[i+1][j+1]++;
                        bom[i-1][j+1]++;
                        bom[i][j+1]++;
                    }else if(j==m-1){
                        bom[i+1][j]++;
                        bom[i-1][j]++;
                        bom[i+1][j-1]++;
                        bom[i-1][j-1]++;
                        bom[i][j-1]++;
                    }else{
                        bom[i+1][j]++;
                        bom[i+1][j+1]++;
                        bom[i+1][j-1]++;
                        bom[i][j+1]++;
                        bom[i][j-1]++;
                        bom[i-1][j]++;
                        bom[i-1][j+1]++;
                        bom[i-1][j-1]++;
                    }
                }
            }
        }
        //part-output
        cout<<"Field #"<<ron<<":"<<"\n";
        ron++;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(bom[i][j]>=9){cout<<"*";}
                else{cout<<bom[i][j];}
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
