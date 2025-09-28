#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<iostream>//zj max歸於iostream下

using namespace std;

int d[5][6]={//0~3垂直mpr變化;4總格變化;5do round
{1,1,1,1,4,4},//A
{3,0,0,0,3,1},//B
{2,2,0,0,4,2},//C
{1,3,0,0,4,2},//D
{1,2,2,0,5,3} //E
};
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
    int R,C,n;
    R=read();
    C=read();
    n=read();
    int br=0,de=R*C,mpr[R]={0};
    while(n--){
        int type;
        type=int(getchar()-'A');
        R=read();
        //do
        int upd=-1;
        for(int i=0;i<d[type][5];i++){
            upd=max(upd,mpr[R+i]+d[type][i]);
        }
        if(upd<=C){
            for(int i=0;i<d[type][5];i++){
                mpr[R+i]=upd;
            }
            de-=d[type][4];
        }else{
            br++;
        }/*
        for(int i=0;i<R;i++){
            cout<<mpr[i]<<" ";
        }
        cout<<"\n";*/
    }
    write(de);
    putchar(' ');
    write(br);
    return 0;
}
