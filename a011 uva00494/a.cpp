#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
        while(getline(cin,a)){

            int check=0,cou=0;
            if((a[0]>=65 && a[0]<=90)||(a[0]>=97 && a[0]<=122)){check=0;}else{check=1;}
            //check=0->zi,check=1->fu
            for(int i=0;i<a.size();i++){
                if((a[i]>=65 && a[i]<=90)||(a[i]>=97 && a[i]<=122)){
                    if(check==1){
                        check=0;
                        cou++;
                    }
                }else{
                    check=1;
                }

            }
            cout<<cou+1<<"\n";
        }
    //A=65,Z=90,a=97,z=122
    return 0;
}
