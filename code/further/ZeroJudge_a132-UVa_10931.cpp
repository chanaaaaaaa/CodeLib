#include <bits/stdc++.h>
using namespace std;

inline int pow2(int depth){
    if(depth==0){return 1;}
    return 2*pow2(depth-1);
}

int main(){
    int num;
    while(cin>>num && num){
        string out="";
        int cnt=0;
        for(int i=30;i>=0;i--){
            int tmp=pow2(i);
            if(num>=tmp){
                out+='1';
                cnt+=1;
                num-=tmp;
            }else if(cnt>0){out+='0';}
        }
        cout<<"The parity of "<<out<<" is "<<cnt<<" (mod 2).\n";
    }
    return 0;
}
