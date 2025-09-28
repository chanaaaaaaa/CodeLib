#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin>>num;
    cin.ignore();
    for(int i=1;i<=num;i++){
        string team,judge;
        int maxx;
        getline(cin,team);
        getline(cin,judge);

        if(team.size()>judge.size()){
            maxx=team.size();
        }else{maxx=judge.size();}

        int check=0;//0->AC/1->ERR_SPACE(32)/2->WA
        int a=0,b=0;

        for(int j=0;j<maxx;j++){
            if(team[a]==judge[b]){
                a++;
                b++;
            }else if(team[a]!=judge[b]){
                if(team[a]=='/0'||judge[b]=='/0'){break;}
                if(team[a]==' '){a++;check=1;}
                else if(team[a]!=' ' && judge[b]!=' '){check=2;break;}
            }
        }
        cout<<"Case "<<i<<": ";
        if(check==0){cout<<"Yes";}
        else if(check==1){cout<<"Output Format Error";}
        else if(check==2){cout<<"Wrong Answer";}
        cout<<"\n";
    }
    return 0;
}
