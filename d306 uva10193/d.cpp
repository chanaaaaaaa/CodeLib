#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int gc(int a,int b){
    return a ? gc(b%a,a) : b;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin>>N;
    for(int j=1;j<=N;j++){
        cout<<"Pair #"<<j<<": ";

        string temp;
        long a=0,b=0;
        //input
        cin>>temp;
        for(int i=0;i<temp.size();i++){
            a*=2;
            if(temp[i]=='1'){
                a++;
            }
        }
        cin>>temp;
        for(int i=0;i<temp.size();i++){
            b*=2;
            if(temp[i]=='1'){
                b++;
            }
        }
        //doing
        if(gc(a,b)==1){
            cout<<"Love is not all you need!";
        }else{cout<<"All you need is love!";}
        cout<<"\n";
    }
    return 0;
}
