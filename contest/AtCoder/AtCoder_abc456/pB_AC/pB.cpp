#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

signed main(){
    int dat[3][6];
    for(int i=0;i<3;++i){
        for(int j=0;j<6;++j){
            cin>>dat[i][j];
        }
    }

    int res=0;
    for(int i=0;i<6;++i){
        for(int j=0;j<6;++j){
            for(int k=0;k<6;++k){
                if((dat[0][i]==4 && dat[1][j]==5 && dat[2][k]==6)||
                   (dat[0][i]==4 && dat[1][j]==6 && dat[2][k]==5)||
                   (dat[0][i]==5 && dat[1][j]==4 && dat[2][k]==6)||
                   (dat[0][i]==5 && dat[1][j]==6 && dat[2][k]==4)||
                   (dat[0][i]==6 && dat[1][j]==4 && dat[2][k]==5)||
                   (dat[0][i]==6 && dat[1][j]==5 && dat[2][k]==4)
                ){
                    ++res;
                }
            }
        }
    }
    cout<<fixed<<setprecision(10)<<res/216.0<<'\n';
    return 0;
}
