#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long a;
    int ton,con=1;

    while(cin >> a){
        long long re=a;
        int head=0;
        if(a>100000000){
            ton=2;
        }else{
            ton=1;
        }
        if(con>=1000){
            cout << con <<". ";
        }else if(con>=100){
            cout <<" "<< con <<". ";
        }else if(con>=10){
            cout <<"  "<< con <<". ";
        }else if(con>=1){
            cout <<"   "<< con <<". ";
        }

        for(int i=ton;i>0;i--){
            int temp=0;
            if(a>=pow(10,7*i)){
                head=1;
                temp=a/pow(10,7*i);
                a-=temp*pow(10,7*i);
                cout << temp << " kuti ";
            }else if(head==1){cout << "kuti ";}
            if(a>=pow(10,7*i-2)){
                head=1;
                temp=a/pow(10,7*i-2);
                a-=temp*pow(10,7*i-2);
                cout << temp << " lakh ";
            }
            if(a>=pow(10,7*i-4)){
                head=1;
                temp=a/pow(10,7*i-4);
                a-=temp*pow(10,7*i-4);
                cout << temp << " hajar ";
            }
            if(a>=pow(10,7*i-5)){
                head=1;
                temp=a/pow(10,7*i-5);
                a-=temp*pow(10,7*i-5);
                cout << temp << " shata ";
            }
        }
        if(a>0){
            cout << a << "\n";
        }else if(re==0){
            cout << re << "\n";
        }else{
            cout << "\n";
        }
        con++;
    }

    return 0;
}
