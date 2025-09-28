#include <bits/stdc++.h>
using namespace std;

int num;
int main(){
    while(cin >> num){
        if(num==0){break;}
        int check=0,con=0;
        cout <<"The parity of ";
        for(int i=30;i>=0;i--){
            int temp=pow(2,i);
            if(check==2){
                cout<<"0";
            }
            else if(num>temp){
                check=1;
                num-=temp;
                con++;
                cout<<"1";
            }else if(num==temp){
                check=2;
                num-=temp;
                con++;
                cout<<"1";
            }else if(check==1){
                cout<<"0";
            }
        }
        cout<<" is "<<con<<" (mod 2)."<<"\n";
    }
    return 0;
}
