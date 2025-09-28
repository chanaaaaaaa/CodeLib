#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c;
    cin >>a>>b>>c;

    if(b*b-4*a*c==0){
        cout<<"Two same roots x="<<b*-1/2/a;
    }else if(b*b-4*a*c<0){
        cout<<"No real root";
    }else{
        int ans1=(b*-1+sqrt(b*b-4*a*c))/2/a,ans2=(b*-1-sqrt(b*b-4*a*c))/2/a;
        if(ans2>ans1){
            int temp=ans1;
            ans1=ans2;
            ans2=temp;
        }
        cout<<"Two different roots x1="<<ans1<<" , x2="<<ans2;
    }
    //-b+_g.b*b-4ac)/2a
    return 0;
}
