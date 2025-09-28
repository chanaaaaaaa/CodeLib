#include<bits/stdc++.h>
using namespace std;
struct job{
  int x,y;
  int step;
};
int dx[]={3,3,1,-1,-3,-3,1,-1};
int dy[]={1,-1,3,3,1,-1,-3,-3};
int mind=999999;
bool ta[105][105];
bool ta1[105][105];
int jx[]={1,0,-1,0};
int jy[]={0,1,0,-1};
deque<job>now;
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int sx,sy;
  int gp,gk;
  int ex,ey;
  int n;
  job next,num;
  while(cin >> n){
    now.clear();
    memset(ta,0,sizeof(ta));
    memset(ta1,0,sizeof(ta1));
    mind=999999;
      for(int x=0;x<n;x++){
      cin >> gp >> gk;
      ta[gp][gk]=true;
    }
    cin >> sx >> sy;
    cin >> ex >> ey;
    next.x=sx;
    next.y=sy;
    next.step=0;
    ta1[sx][sy]=true;
    int kx,ky;
    now.push_back(next);
    bool ta2=false;
    while(!now.empty()){
      next=now.front();
      now.pop_front();
      for(int z=0;z<4;z++){
        if(ta2){
          break;
        }
        kx=next.x+jx[z];
        ky=next.y+jy[z];
        if(!ta[kx][ky] && (kx>=0 && kx<=99) && (ky>=0 && ky<=99)){
          for(int g=2*z;g<=(2*z)+1;g++){
            kx=next.x+dx[g];
            ky=next.y+dy[g];
            num.step=next.step+1;
            num.x=kx;
            num.y=ky;
            if(!ta[kx][ky] && !ta1[kx][ky] && (kx>=0 && kx<=99) && (ky>=0 && ky<=99) && (kx!=(ex) or ky!=(ey))){
              ta1[num.x][num.y]=true;
              now.push_back(num);
            }
            else if(!ta[kx][ky] && !ta1[kx][ky] && (kx>=0 && kx<=99) && (ky>=0 && ky<=99) && (kx==(ex) && ky==(ey))){
              mind=num.step;
              now.clear();
              ta2=true;
              break;
            }
          }
        }
      }
    }
    if(mind!=999999)
    cout << mind << endl;
    else{
      cout << "impossible" << endl;
    }
  }

  return 0;
}
