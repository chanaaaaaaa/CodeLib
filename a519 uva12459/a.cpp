#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,now=1;
    long long bee[81];
    bee[0]=1;
    bee[1]=1;
    while(cin>>a){
        if(a==0){break;}

        if(a>now){
            for(int n=now+1;n<=a;n++){
                bee[n]=bee[n-1]+bee[n-2];
                now++;
            }
        }
        cout<<bee[a]<<"\n";
    }
    return 0;
}
