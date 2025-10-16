#include<iostream>
#include<fstream>
using namespace std;

signed main(){

    ofstream dataFile;
    dataFile.open("test.csv", ios::out | ios::trunc);
    for(int i=0;i<26;i++){
        dataFile<<i+1<<" ."<<char('A'+i)<<'\n';
    }
    dataFile.close();
    return 0;
}
