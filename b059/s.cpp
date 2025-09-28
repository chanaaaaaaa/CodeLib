#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

struct f{
    int x,y,step;
};
deque<f>now;
int xm[]={1,-1,-3,-3,-1,1,3,3}; //move
int ym[]={3,3,1,-1,-3,-3,-1,1};
int cx[]={0,-1,0,1};            //check
int cy[]={1,0,-1,0};
bool ma[105][105];              //map
bool maed[105][105];            //maped
int Ans=0x7fffffff;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;      //time
    int sx,sy;  //stone
    int dx,dy;  //dog
    int tx,ty;  //target
    f next,num;
    while(cin>>N){
        //init
        Ans=0x7fffffff;
        now.clear();
        memset(ma,0,sizeof(ma));
        memset(maed,0,sizeof(maed));
        for(int i=0;i<N;i++){
            cin>>sx>>sy;
            ma[sx][sy]=true;
        }
        //dog
        //target
        cin>>dx>>dy;
        cin>>tx>>ty;
        next.x=dx;
        next.y=dy;
        next.step=0;
        now.push_back(next);
        maed[dx][dy]=true;
        //doing
        int tempx,tempy;
        bool flag=false;
        while(!now.empty()){
            next=now.front();
            now.pop_front();
            for(int face=0;face<4;face++){
                if(flag)break;
                tempx=next.x+cx[face];
                tempy=next.y+cy[face];
                if(!ma[tempx][tempy] && (tempx>=0 && tempx<=99) && (tempy>=0 && tempy<=99)){
                    for(int j=2*face;j<=(2*face)+1;j++){
                        num.x=next.x+xm[j];
                        num.y=next.y+ym[j];
                        num.step=next.step+1;
                        if(!ma[num.x][num.y] && !maed[num.x][num.y] && (num.x>=0 && num.x<=99) && (num.y>=0 && num.y<=99) && (num.x!=tx || num.y!=ty)){
                            maed[num.x][num.y]=true;
                            now.push_back(num);
                        }else if(!ma[num.x][num.y] && !maed[num.x][num.y] && (num.x>=0 && num.x<=99) && (num.y>=0 && num.y<=99) && (num.x==tx && num.y==ty)){
                            Ans=num.step;
                            now.clear();
                            flag=true;
                            break;
                        }
                    }
                }
            }
        }
        if(Ans!=0x7fffffff){
            cout<<Ans<<"\n";
        }else{
            cout<<"impossible\n";
        }
    }
    return 0;
}
