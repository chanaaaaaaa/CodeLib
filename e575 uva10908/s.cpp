#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

string A[100];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int T,M,N,Q,r,c;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>T;
    while(T--){
        cin>>M>>N>>Q;
        cout<<M<<" "<<N<<" "<<Q<<"\n";
        for(int i=0;i<M;i++){
            cin>>A[i];
        }
        for(int g=0;g<Q;g++){
            cin>>r>>c;
            int Ans=-10,limit=min(M,N);

            for(int i=1;i<=limit;i++){
                int rex=r-i,rey=c-i;
                for(int j=0;j<4;j++){
                    for(int k=0;k<i*2;k++){
                        rex+=dir[j][0];
                        rey+=dir[j][1];
                        if(rex<0 || rex>=M || rey<0 || rey>=N || A[rex][rey]!=A[r][c]){
                            Ans=i;
                            break;
                        }
                    }
                    if(Ans!=-10){break;}
                }
                if(Ans!=-10){break;}
            }
        cout<<Ans*2-1<<"\n";
        }
    }
    return 0;
}
