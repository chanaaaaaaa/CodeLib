#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>A,B;
int N;
signed main(){
    while(cin>>N){
        A.resize(N);
        B.resize(N);
        for(int i=0;i<N;++i){cin>>A[i];}
        for(int i=0;i<N;++i){cin>>B[i];}

        int L=-1,R=-1;
        for(int i=0;i<N;++i){
            if(A[i]!=B[i]){
                if(L==-1){L=i;}
                R=i;
            }
        }
        if(L==-1){
            cout<<"Yes\n";
            continue;
        }
        bool left=B[R]==A[L];
        for(int i=L;i<R&&left;++i){
            if(B[i]!=A[i+1]){left=false;}
        }
        bool right=B[L]==A[R];
        for(int i=L+1;i<=R&&right;++i){
            if(B[i]!=A[i-1]){right=false;}
        }
        if(left||right){cout<<"Yes\n";}
        else{cout<<"No\n";}
    }
    return 0;
}
