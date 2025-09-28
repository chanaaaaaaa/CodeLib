#include <bits/stdc++.h>
using namespace std;

int gc(int a,int b){
    return b>0? gc(b,a%b):a;
}

int main(){
    int num;
    cin>>num;
    for(int i=0;i<num*2;i++){
        string s;
        int ma[100];
        getline(cin,s);
        int con=0,now=0,amc=0,check=0;
        for(int j=s.size()-1;j>=0;j--){
            if(int(s[j])>=48 && int(s[j])<=57){
                con+=(int(s[j])-48)*pow(10,now);
                now++;
                check=1;
                if(j==0){ma[amc]=con;}
            }else if(check==1){
                ma[amc]=con;
                con=0;
                now=0;
                amc++;
                check=0;
            }
        }
        if(amc>0){
            int maxx=1;
            for(int j=0;j<=amc-1;j++){
                for(int g=j+1;g<=amc;g++){
                    int temp=gc(ma[j],ma[g]);
                    if(temp>maxx){maxx=temp;}
                }
            }
            cout << maxx <<"\n";
        }
    }
    return 0;
}
