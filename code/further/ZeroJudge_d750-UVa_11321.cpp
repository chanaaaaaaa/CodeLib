#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int A,B;
    while(cin>>A>>B){
        cout<<A<<" "<<B<<"\n";
        if(A+B==0){break;}
        vector<int>dat;
        for(int i=0;i<A;i++){
            int temp;
            cin>>temp;
            dat.push_back(temp);
        }
        for(int i=0;i<A-1;i++){
            for(int j=i+1;j<A;j++){
                if(dat[i]%B > dat[j]%B){
                    swap(dat[i],dat[j]);
                }
            }
        }
        for(int i=0;i<A-1;i++){
            for(int j=i+1;j<A;j++){
                if(dat[i]%B==dat[j]%B){
                    if(dat[i]%2+dat[j]%2==0){
                        if(dat[i]>dat[j]){
                            swap(dat[i],dat[j]);
                        }
                    }else if(dat[i]%2+dat[j]%2==1){
                        if(dat[j]%2==1){
                            swap(dat[i],dat[j]);
                        }
                    }else{//dat[i]%2+dat[j]%2==2
                        if(dat[i]<dat[j]){
                            swap(dat[i],dat[j]);
                        }
                    }
                }
            }
        }
        for(int i=0;i<A;i++){
            cout<<dat[i]<<"\n";
        }
    }
    return 0;
}
