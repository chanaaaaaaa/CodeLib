#include<bits/stdc++.h>

using namespace std;

string in;
int dice[3][4];
int a;

int main(){

    while(cin>>a){
        if(a==0){break;}
        dice[1][0]=1;
        dice[1][1]=2;
        dice[1][2]=6;
        dice[1][3]=5;
        dice[0][2]=3;
        dice[2][2]=4;

        for(int i=0;i<a;i++){
            cin >> in;
            if(in=="north"){
                swap(dice[1][3],dice[1][0]);
                swap(dice[1][3],dice[1][1]);
                swap(dice[1][3],dice[1][2]);
            }else if(in=="south"){
                swap(dice[1][0],dice[1][3]);
                swap(dice[1][0],dice[1][2]);
                swap(dice[1][0],dice[1][1]);
            }else if(in=="east"){
                swap(dice[0][2],dice[1][2]);
                swap(dice[1][2],dice[2][2]);
                swap(dice[2][2],dice[1][0]);
            }else if(in=="west"){
                swap(dice[1][2],dice[2][2]);
                swap(dice[0][2],dice[1][2]);
                swap(dice[0][2],dice[1][0]);
            }
        }
        cout << dice[1][0] <<"\n";
    }

    return 0;
}


while 1:

    a=int(input())
    if a==0:
        break
    elif a%11==0 :
        print(a,"is a multiple of 11.")
    else :
        print(a,"is not a multiple of 11.")
