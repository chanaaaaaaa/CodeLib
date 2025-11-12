#include<iostream>
#include<math.h>
#include<algorithm>
#include<climits>
using namespace std;


signed main(){
    int N,M;
    cin>>N>>M;
    int DN[N],DM[M];
    for(int i=0;i<N;i++){
        cin>>DN[i];
    }
    for(int i=0;i<M;i++){
        cin>>DM[i];
    }
    sort(DN,DN+N);
    sort(DM,DM+M);
    //-input
    int idx_N=0,idx_M=0,minn=INT_MAX;
    while(idx_N<N && idx_M<M){
        minn=min(minn,abs(DN[idx_N]-DM[idx_M]));
        /*
        write(DN[idx_N]);
        putchar(' ');
        write(DM[idx_M]);
        putchar('\n');
        */
        if(DN[idx_N]==DM[idx_M]){
            minn=0;
            break;
        }else if(DN[idx_N]>DM[idx_M]){
            idx_M++;
        }else if(DN[idx_N]<DM[idx_M]){
            idx_N++;
        }
    }
    cout<<minn<<"\n";
    return 0;
}
