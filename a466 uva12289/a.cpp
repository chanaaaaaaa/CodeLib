#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        string K;
        cin>>K;
        if(K.size()==5){
            cout<<"3"<<"\n";
        }else{
            string one="one";
            string two="two";
            int a=0,b=0;
            for(int j=0;j<3;j++){
                if(K[j]==one[j]){
                    a++;
                }else if(K[j]==two[j]){
                    b++;
                }
            }
            if(a>=2){
                cout<<"1"<<"\n";
            }else if(b>=2){
                cout<<"2"<<"\n";
            }
        }


    }
    return 0;
}
