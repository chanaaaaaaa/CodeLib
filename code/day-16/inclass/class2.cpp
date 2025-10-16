#include<iostream>
#include<fstream>
using namespace std;

signed main(){

    ifstream inFile("test.csv", ios::in);
    if(!inFile){cout<<"shit error\n";return 0;}
    string line;
    while(getline(inFile,line)){
        int t=0;
        for(int i=0;i<2;i++){
            if(line[i]<='9' && line[i]>='0'){
                t=t*10+line[i]-'0';
            }
        }
        for(int i=0;i<t;i++){
            if(t>=10){
                cout<<line[4];
            }else{
                cout<<line[3];
            }
        }
        cout<<"\n";
    }
    return 0;
}
