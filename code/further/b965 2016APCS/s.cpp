#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int dat[10][10];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int R,C,M;
    bool check=true;
    while(cin>>R>>C>>M){
        if(check)check=false;
        else cout<<"\n";
        //input
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cin>>dat[i][j];
            }
        }
        //doing
        vector<int>step;
        for(int i=0;i<M;i++){
            int temp;
            cin>>temp;
            step.push_back(temp);
        }
        for(int i=0;i<M;i++){
            if(step[M-1-i]!=0){//fan
                for(int j=0;j<C;j++){
                    for(int i=0;i<R/2;i++){
                        int temp=dat[i][j];
                        dat[i][j]=dat[R-1-i][j];
                        dat[R-1-i][j]=temp;
                    }
                }
            }else{//rotate
                int temp[10][10] = {0};
                for(int i=0;i<C;i++){
                    for(int j=0;j<R;j++){
                        temp[i][j]=dat[j][C-1-i];
                    }
                }

                int t=R;
                R=C;
                C=t;
                for(int i=0;i<R;i++){
                    for(int j=0;j<C;j++) dat[i][j]=temp[i][j];
                }
            }
        }
        cout<<R<<" "<<C<<"\n";
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cout<<dat[i][j];
                if(j!=C-1) cout<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
