#include <cstdio>

using namespace std;

inline int read(){
    int x=0,c=0,w=1;
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

inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}

int T;
signed main(){
    while(T=read()){
        while(T--){
            long long Px=read(),Py=read();
            long long Qx=read(),Qy=read();
            long long Rx=read(),Ry=read();
            long long Sx=read(),Sy=read();

            long long PQx=Px-Qx,PQy=Py-Qy;
            long long RSx=Rx-Sx,RSy=Ry-Sy;

            long long cro=PQx*RSy-PQy*RSx;
            if(cro!=0){
                printf("Yes\n");
            }else{
                long long MPQx=Px+Qx,MPQy=Py+Qy;
                long long MRSx=Rx+Sx,MRSy=Ry+Sy;

                cro=(MPQx-MRSx)*PQx+(MPQy-MRSy)*PQy;
                if(cro==0){
                    printf("Yes\n");
                }else{
                    printf("No\n");
                }
            }
        }
    }
    return 0;
}
