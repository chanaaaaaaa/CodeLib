#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
using namespace std;

int mx[4]={0,0,-1,1};
int my[4]={1,-1,0,0};
int dat[100][100];

int n,m,sx=0,sy=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>dat[j][i];
            if(dat[j][i]<dat[sx][sy]){
                sx=j;
                sy=i;
            }
        }
    }
    long long Ans=dat[sx][sy];
    for(int i=0;i<n*m;i++){
        int nowx=sx,nowy=sy,maxx=1e6;
        for(int j=0;j<4;j++){
            if(nowx+mx[j]<m && nowx+mx[j]>=0 && nowy+my[j]<n && nowy+my[j]>=0){
                if((dat[nowx+mx[j]][nowy+my[j]]!=-1)&&(dat[nowx+mx[j]][nowy+my[j]]<maxx)){
                    sx=nowx+mx[j];
                    sy=nowy+my[j];
                    maxx=dat[sx][sy];
                }
            }
        }
        if(sx==nowx && sy==nowy){
            break;
        }else{
            Ans+=dat[sx][sy];
            dat[nowx][nowy]=-1;
        }
    }
    cout<<Ans<<"\n";/*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dat[j][i]<<"\t";
        }
        cout<<"\n";
    }*/
    return 0;
}
