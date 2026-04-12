#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<cstdio>
#include<cstring>

#define int long long
using namespace std;

inline int read(){
    int x=0;char c=0;
    while(c<'0'||c>'9'){
        c=getchar();
        if(c==-1)return 0;
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
//
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
inline bool Prime(int n){
    if(n==2){return true;}
    if(n%2==0 || n<2){return false;}
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0){return false;}
    }
    return true;
}

bool PrimeD(int date){
    char s[20];
    sprintf(s,"%08lld",date);

    for(int i=0;i<strlen(s);i++){
        int suffix=0;
        bool found=0;
        for(int j=i;j<strlen(s);j++){
            int d=s[j]-'0';
            if(d||found){suffix=suffix*10+d;found=1;}
        }
        if(!found||!Prime(suffix)){return false;}
    }
    return true;
}

bool Valid(int y,int m,int d){
    if(m<1||m>12||d<1){return false;}

    if(m==2){
        if((y%4==0&&y%100!=0)||(y%400==0)){
            return d<=29;
        }else{
            return d<=28;
        }
    }
    return d<=days[m-1];
}

void nextDate(int &y,int &m,int &d){
    int maxd;
    d++;
    if(m==2){
        if((y%4==0&&y%100!=0)||(y%400==0)){
            maxd=29;
        }else{
            maxd=28;
        }
    }else{maxd=days[m-1];}

    if(d>maxd){d=1;m++;}
    if(m>12){m=1;y++;}
}

signed main(void){
    int date;
    while(date=read()){
        int y=date/10000,m=(date/100)%100,d=date%100;
        nextDate(y,m,d);
        while(y<=9999){
            if(Valid(y,m,d)&&PrimeD(y*10000+m*100+d)){
                printf("%04lld%02lld%02lld\n",y,m,d);
                break;
            }
            nextDate(y,m,d);
        }
        if(y>9999)printf("Too much digits!!!\n");
    }
}
