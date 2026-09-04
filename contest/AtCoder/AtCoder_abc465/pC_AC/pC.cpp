#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool f;
int N;
string S;
vector<int>A,B;
signed main(){
    while(cin>>N>>S){
        f=false;
        A.clear();B.clear();

        for(int i=0;i<N;++i){
            if(f){
                A.push_back(i+1);
            }else{
                B.push_back(i+1);
            }
            if(S[i]=='o'){
                f=!f;
            }
        }

        reverse(A.begin(),A.end());
        for(const int b:B){
            A.push_back(b);
        }
        if(f){
            reverse(A.begin(),A.end());
        }

        for(const int a:A){
            cout<<a<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
