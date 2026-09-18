#include <iostream>
#include <vector>
using namespace std;

signed main(){
    int W,H;
    while(cin>>H>>W){
        if(H==1 && W==1){
            cout<<"0\n";
            continue;
        }else if(H==1){
            for(int i=0;i<W;++i){
                if(i==0 || i==W-1){
                    cout<<"1 ";
                }else{
                    cout<<"2 ";
                }
            }
            cout<<'\n';
            continue;
        }else if(W==1){
            for(int i=0;i<H;++i){
                if(i==0 || i==H-1){
                    cout<<"1\n";
                }else{
                    cout<<"2\n";
                }
            }
            cout<<'\n';
            continue;
        }

        for(int i=0;i<H;++i){
            for(int j=0;j<W;++j){
                if(i==0 && j==0){
                    cout<<"2 ";
                }else if(i==0 && j==W-1){
                    cout<<"2 ";
                }else if(i==H-1 && j==0){
                    cout<<"2 ";
                }else if(i==H-1 && j==W-1){
                    cout<<"2 ";
                }else if(i==0 || i==H-1 || j==0 || j==W-1){
                    cout<<"3 ";
                }else{
                    cout<<"4 ";
                }
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}
