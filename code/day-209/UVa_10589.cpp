#include <cstdio>

using namespace std;

signed main(){
    int N,A,cnt;
    double x,y;
    while(true){
        scanf("%d %d",&N,&A);
        cnt=0;
        if(N==0 && A==0){break;}

        for(int i=0;i<N;++i){
            scanf("%lf %lf",&x,&y);
            if(x*x+y*y <= A*A &&
                (x-A)*(x-A)+y*y <= A*A &&
                x*x+(y-A)*(y-A) <= A*A &&
                (x-A)*(x-A)+(y-A)*(y-A) <= A*A
            ){
                ++cnt;
            }
        }
        printf("%.5lf\n",(double)cnt*A*A/N);
    }
    return 0;
}