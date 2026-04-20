#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

inline int read(){
    int x=0,w=1,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
        if(c=='-'){w=-1;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}
//-block
inline int max(const int &a,const int &b){
    return a>b?a:b;
}

int T,W,H,type,x,y,dx,dy,res,la;
map<int,vector<int>>tree;
vector<int>height;

vector<int>Ls(10010);
vector<int>Rs(10010);
signed main(){
    while(T=read()){
        while(T--){
            W=read();H=read();
            tree.clear();

            while(type=read()){
                x=read();y=read();
                if(type==1){
                    tree[y].emplace_back(x);
                    continue;
                }

                dx=read();dy=read();
                while(type--){
                    tree[y].emplace_back(x);
                    x+=dx;y+=dy;
                }
            }

            tree[H];
            height.assign(W+1,0);
            res=max(W,H);
            la=0;
            for(map<int,vector<int>>::iterator it=tree.begin();it!=tree.end();++it){
                int dis=it->first-la;
                la+=dis;
                for(int i=1;i<W;++i){
                    height[i]+=dis;
                }

                for(int i=0,j=W;i<=W;++i,--j){
                    for(Ls[i]=i;Ls[i]>0 && height[Ls[i]-1]>=height[i];){
                        Ls[i]=Ls[Ls[i]-1];
                    }
                    for(Rs[j]=j;Rs[j]<W && height[Rs[j]+1]>=height[j];){
                        Rs[j]=Rs[Rs[j]+1];
                    }
                }
                for(int i=0;i<=W;++i){
                    res=max(res,height[i]*(Rs[i]-Ls[i]+2));
                }

                for(int &n:it->second){
                    height[n]=0;
                }
            }
            write(res);
            putchar('\n');
        }
    }
    return 0;
}
