#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<stdio.h>
#include<algorithm>
using namespace std;
int k,q1,q2;

inline bool is_illegal_move(){
    if(k==q2 || q1==q2){return true;}
    if(q1/8!=q2/8 && q1%8!=q2%8){return true;}
    if((((q1/8<k/8 && k/8<q2/8)||(q1/8>k/8 && k/8>q2/8)) && q1%8==k%8 )||(((q1%8<k%8 && k%8<q2%8)||(q1%8>k%8 && k%8>q2%8)) && q1/8==k/8)){
        return true;
    }
    return false;
}

inline bool is_move_not_allow(){
    if((k+1==q2 && q2%8!=0)||(k-1==q2 && q2%8!=7)||(k-8==q2)|| k+8==q2){
        return true;
    }
    return false;
}

inline bool is_stop(){
    if((k==0 && q2==9)||(k==7 && q2==14)||(k==56 && q2==49)||(k==63)&&(q2==54)){
        return true;
    }
    return false;
}

signed main(){
    while(~scanf("%d %d %d",&k,&q1,&q2)){
        if(k==q1){
            printf("Illegal state\n");
        }else if(is_illegal_move()){
            printf("Illegal move\n");
        }else if(is_move_not_allow()){
            printf("Move not allowed\n");
        }else if(is_stop()){
            printf("Stop\n");
        }else{
            printf("Continue\n");
        }
    }

    return 0;
}
