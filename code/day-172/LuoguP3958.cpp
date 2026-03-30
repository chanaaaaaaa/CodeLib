#include <cstdio>
#include <vector>

#define int long long
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*w;
}

struct node{
    int x,y,z;
    node(int _x,int _y,int _z):x(_x),y(_y),z(_z){}
};

int T,N,H,R;
vector<node>mp;
vector<bool>vis;
bool fin;

inline void dfs(int index){
    if(fin || vis[index]){return;}

    vis[index]=true;

    if(mp[index].z+R >= H && mp[index].z-R <= H){fin=true;return;}

    for(int i=0;i<mp.size();++i){
        if(i==index || vis[i] || fin){continue;}

        int dx=mp[i].x-mp[index].x;
        int dy=mp[i].y-mp[index].y;
        int dz=mp[i].z-mp[index].z;

        if(dx*dx+dy*dy+dz*dz <= 4*R*R){
            dfs(i);
        }
    }
    return;
}

inline void solve(){
    mp.clear();
    fin=false;
    N=read();H=read();R=read();
    vis.assign(N,false);

    while(N--){
        mp.push_back({read(),read(),read()});
    }
    
    for(int i=0;i<mp.size();++i){
        if(mp[i].z-R<=0 && mp[i].z+R>=0){
            dfs(i);
        }
        if(fin){break;}
    }

    if(fin){
        putchar('Y');
        putchar('e');
        putchar('s');
    }else{
        putchar('N');
        putchar('o');
    }
    putchar('\n');
    return;
}

signed main(){
    while(T=read()){
        while(T--){
            solve();
        }
    }
    return 0;
}