#include <cstdio>
#include <vector>
#include <string>

using namespace std;

inline int read(){
    int x=0,c=0,w=1;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}

        if(c=='#'){return -1;}//cant in
        if(c=='.'){return 0;}//four ways
        if(c=='o'){return 1;}//same way (1 way)
        if(c=='x'){return 2;}//diff way (3 way)
        if(c=='S'){return 3;}//starting
        if(c=='G'){return 4;}//ending

        if(c==-1){return 0;}
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
int N,M,si,sj,ei,ej;
int d[4][2]={
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};
string S="";
vector<vector<int>>mp;

inline void dfs(int i,int j,int dir,string s){
    if(i==ei && j==ej){
        if(s.size() < S.size()){
            S=s;
        }
        return;
    }
    if(s.size() >= N*M*2){return;}
    if(S!="" && s.size() >= S.size()){return;}

    if(mp[i][j]==0){
        for(int f=0;f<4;++f){
            if(i+d[f][0]<0 || i+d[f][0]>=N || j+d[f][1]<0 || j+d[f][1]>=M || mp[i+d[f][0]][j+d[f][1]]==-1){continue;}

            if(f==0){
                dfs(i+d[f][0],j+d[f][1],f,s+'U');
            }else if(f==1){
                dfs(i+d[f][0],j+d[f][1],f,s+'D');
            }else if(f==2){
                dfs(i+d[f][0],j+d[f][1],f,s+'L');
            }else if(f==3){
                dfs(i+d[f][0],j+d[f][1],f,s+'R');
            }
        }
    }else if(mp[i][j]==1){
        int f=dir;
        if(i+d[f][0]>=0 && i+d[f][0]<N && j+d[f][1]>=0 && j+d[f][1]<M && mp[i+d[f][0]][j+d[f][1]]!=-1){
            if(f==0){
                dfs(i+d[f][0],j+d[f][1],f,s+'U');
            }else if(f==1){
                dfs(i+d[f][0],j+d[f][1],f,s+'D');
            }else if(f==2){
                dfs(i+d[f][0],j+d[f][1],f,s+'L');
            }else if(f==3){
                dfs(i+d[f][0],j+d[f][1],f,s+'R');
            }
        }
    }else if(mp[i][j]==2){
        for(int f=0;f<4;++f){
            if(i+d[f][0]<0 || i+d[f][0]>=N || j+d[f][1]<0 || j+d[f][1]>=M || f==dir || mp[i+d[f][0]][j+d[f][1]]==-1){continue;}

            if(f==0){
                dfs(i+d[f][0],j+d[f][1],f,s+'U');
            }else if(f==1){
                dfs(i+d[f][0],j+d[f][1],f,s+'D');
            }else if(f==2){
                dfs(i+d[f][0],j+d[f][1],f,s+'L');
            }else if(f==3){
                dfs(i+d[f][0],j+d[f][1],f,s+'R');
            }
        }
    }
    return;
}

signed main(){
    N=read();M=read();
    mp.assign(N,vector<int>(M));

    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            mp[i][j]=read();
            if(mp[i][i]==3){
                si=i;sj=j;
                mp[i][j]=0;
            }else if(mp[i][j]==4){
                ei=i;ej=j;
                mp[i][j]=0;
            }
        }
    }
    dfs(si,sj,-1,"");
    if(S!=""){
        printf("Yes\n%s\n",S);
    }else{
        printf("No\n");
    }
    return 0;
}
