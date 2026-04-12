#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <iostream>
#include <set>
using namespace std;

set<int>out;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int X,Y;
    cin>>X>>Y;

    int x,y,f;//N=0,E=1,S=2,W=3
    char face;
    while(cin>>x>>y>>face){
        string go;
        cin>>go;
        if(face=='N'){
            f=0;
        }else if(face=='E'){
            f=1;
        }else if(face=='S'){
            f=2;
        }else if(face=='W'){
            f=3;
        }
        for(int i=0;i<go.size();i++){
            char temp=go[i];
            if(temp=='R'){
                f++;
                if(f>3){f-=4;}
            }else if(temp=='L'){
                f--;
                if(f<0){f+=4;}
            }else if(temp=='F'){
                //important
                if(f==0){
                    if(out.count(x*100+y+1)){
                        continue;
                    }else{y++;}
                }else if(f==1){
                    if(out.count((x+1)*100+y)){
                        continue;
                    }else{x++;}
                }else if(f==2){
                    if(out.count(x*100+y-1)){
                        continue;
                    }else{y--;}
                }else if(f==3){
                    if(out.count((x-1)*100+y)){
                        continue;
                    }else{x--;}
                }

                if(x<0 || y<0 || y>Y || x>X){
                    char temp;
                    if(f==0){
                        temp='N';
                    }else if(f==1){
                        temp='E';
                    }else if(f==2){
                        temp='S';
                    }else if(f==3){
                        temp='W';
                    }
                    if(x<0){
                        cout<<x+1<<" "<<y<<" "<<temp<<" LOST"<<"\n";
                    }else if(x>X){
                        cout<<x-1<<" "<<y<<" "<<temp<<" LOST"<<"\n";
                    }else if(y<0){
                        cout<<x<<" "<<y+1<<" "<<temp<<" LOST"<<"\n";
                    }else if(y>Y){
                        cout<<x<<" "<<y-1<<" "<<temp<<" LOST"<<"\n";
                    }
                    if(x==-1){
                       if(y==0){
                            out.insert(-100);//x=-1,y=0
                            out.insert(-1);//x=0,y=-1
                       }else if(y==Y){
                            out.insert(-100+y);//x=-1,y=Y
                            out.insert(Y+1);//x=0,y=Y+1
                       }
                    }else if(x==X+1){
                        if(y==0){
                            out.insert(x*100);//x=X+1,y=0
                            out.insert(X*100-1);//x=X,y=-1
                       }else if(y==Y){
                            out.insert(x*100+Y);//x=X+1,y=Y
                            out.insert(X*100+Y+1);//x=X,y=Y+1
                       }
                    }else if(y==-1){
                        if(x==0){
                            out.insert(-1);//x=0,y=-1
                            out.insert(-100);//x=-1,y=0
                       }else if(x==X){
                            out.insert(x*100-1);//x=X,y=-1
                            out.insert((X+1)*100);//x=X+1,y=0
                       }
                    }else if(y==Y+1){
                        if(x==0){
                            out.insert(y);//x=0,y=Y+1
                            out.insert(Y-100);//x=-1,y=Y
                       }else if(x==X){
                            out.insert(x*100+y);//x=X,y=Y+1
                            out.insert((X+1)*100+Y);//x=X+1,y=Y
                       }
                    }
                    out.insert(x*100+y);
                    break;
                }
            }
            if(i==go.size()-1){
                char temp;
                if(f==0){
                    temp='N';
                }else if(f==1){
                    temp='E';
                }else if(f==2){
                    temp='S';
                }else if(f==3){
                    temp='W';
                }
                cout<<x<<" "<<y<<" "<<temp<<"\n";
            }
        }
    }
    return 0;
}
