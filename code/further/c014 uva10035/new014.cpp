#include<bits/stdc++.h>

using namespace std;

int a,b,con=0;
int aa[10],bb[10],cc[11];

int main(){

    while(true){
        for(int i=10;i>0;i--){
            cc[i]=0;
        }
        con=0;

        cin>>a>>b;
        if(a+b==0){break;}

        for(int i=9;i>0;i--){
            int na,nb;
            na=(a/pow(10,10-1-i));
            aa[i]=na%10;
            nb=(b/pow(10,10-1-i));
            bb[i]=nb%10;
            cc[i+1]+=aa[i]+bb[i];
            if(cc[i+1]>=10){
                cc[i+1]-=10;
                cc[i]+=1;
                con++;
            }
        }
        if(con>1){
            cout<<con<<" carry operations."<<"\n";
        }else if(con>0){
            cout<<con<<" carry operation."<<"\n";
        }else{
           cout<<"No carry operation."<<"\n";
        }
    }
    return 0;
}
