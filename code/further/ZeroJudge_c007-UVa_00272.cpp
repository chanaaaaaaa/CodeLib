#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string A;
    int check=0;
    while(getline(cin,A)){

        for(int i=0;i<A.size();i++){
            if(A[i]=='"'){
                if(check==0){
                    check=1;
                    cout<<"``";
                }else{
                    check=0;
                    cout<<"''";
                }
            }else{cout<<A[i];}
        }
        cout<<"\n";
    }
    return 0;
}
