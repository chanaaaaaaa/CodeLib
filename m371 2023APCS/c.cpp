#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>

using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0'&& c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main(){
    int n,m,Ans=0;;
    n=read();
    m=read();
    int mp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mp[i][j]=read();
        }
    }
    bool flag=true;
    while(flag){
        flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mp[i][j]==-1){continue;}
                if(i+1<n){
                    //putchar('i');
                    for(int k=i+1;k<n;k++){
                        if(mp[k][j]==-1){continue;}
                        else if(mp[k][j]!=mp[i][j]){break;}
                        else{
                            Ans+=mp[i][j];
                            mp[i][j]=-1;
                            mp[k][j]=-1;
                            flag=true;
                            break;
                        }
                        if(flag){break;}
                    }
                }
                if(j+1<m && !flag){
                    //putchar('j');
                    for(int k=j+1;k<m;k++){
                        if(mp[i][k]==-1){continue;}
                        else if(mp[i][k]!=mp[i][j]){break;}
                        else{
                            Ans+=mp[i][k];
                            mp[i][j]=-1;
                            mp[i][k]=-1;
                            flag=true;
                            break;
                        }
                        if(flag){break;}
                    }
                }
                if(flag){break;}
            }
        }/*
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                write(mp[i][j]);
                putchar(' ');
            }
            putchar('\n');
        }
        putchar('\n');*/
    }
    write(Ans);
    return 0;
}
