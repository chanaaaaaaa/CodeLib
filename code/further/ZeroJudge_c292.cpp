#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int dat[49][49];
int mx[4]={0,-1,0,1};
int my[4]={-1,0,1,0};

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N,F;
    cin>>N>>F;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>dat[i][j];
        }
    }
    int x=(N-1)/2,y=x;
    cout<<dat[x][y];
    for(int i=1;i<N;i++){//_move_num
        for(int j=0;j<2;j++){//move2t per num
            for(int g=0;g<i;g++){
                x+=mx[F%4];
                y+=my[F%4];
                cout<<dat[x][y];
            }
            F++;
        }
        if(i==N-1){
            for(int g=0;g<i;g++){
                x+=mx[F%4];
                y+=my[F%4];
                cout<<dat[x][y];
            }
        }
    }
    return 0;
}
