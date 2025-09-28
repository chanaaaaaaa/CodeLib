#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <stdio.h>
#include<vector>
using namespace std;

int q,t,l,r,A;
vector<int>d;

int main(){

    scanf("%d %d",&t,&q);
    d.reserve(t+1);
    while(t--){
        scanf("%d",&A);
        d.push_back(A);
    }

    while(q--){
        scanf("%d %d %d",&t,&l,&r);
        if(t==1){
            for(l--;l<r;l++){
                if((d[l]&1)==1){
                    d[l]=d[l]*3+1;
                }else{
                    d[l]/=2;
                }
            }
        }else{
            A=0;
            for(l--;l<r;l++){
                A+=d[l];
            }
            printf("%d\n",A);
        }
    }
    return 0;
}
