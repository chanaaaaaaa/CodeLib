#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")

#include<iostream>
#include<sstream>

using namespace std;

signed main() {
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string A;
        stringstream AA;
        getline(cin,A);
        AA<<A;

        int check=0,con=0;
        while(AA>>A){
            con++;
            if(A=="MM"){check++;}
            else if(A=="FF"){check--;}
        }
        if(!check && con>1){cout<<"LOOP\n";}
        else{cout<<"NO LOOP\n";}
    }
    return 0;
}
