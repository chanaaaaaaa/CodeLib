#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int con=1;
    while(cin>>s){
        if(s=="#"){break;}
        cout<<"Case "<<con<<": ";
        if(s=="HELLO"){
            cout<<"ENGLISH";
        }else if(s=="HOLA"){
            cout<<"SPANISH";
        }else if(s=="HALLO"){
            cout<<"GERMAN";
        }else if(s=="BONJOUR"){
            cout<<"FRENCH";
        }else if(s=="CIAO"){
            cout<<"ITALIAN";
        }else if(s=="ZDRAVSTVUJTE"){
            cout<<"RUSSIAN";
        }else{
            cout<<"UNKNOWN";
        }
        cout<<"\n";
        con++;
    }

    return 0;
}
