#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<cstdio>
#include<vector>
#include<algorithm>

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

int n;
vector<vector<int>>t;
vector<int>ass;
vector<vector<int>>order;

inline int minTime(int i,int j){

    int assignedProb=-1;
    for(int k=0;k<n;k++){
        if(ass[k]==i){
            assignedProb=k;
            break;
        }
    }

    if(assignedProb==-1){
        vector<int>perm;
        for(int k=0;k<n;k++){perm.push_back(k);}
        int res=1e9;
        do{
            int time=0;
            for(int k=0;k<n;k++){
                time+=t[i][perm[k]];
                if(perm[k]==j){
                    res=min(res,time);
                    break;
                }
            }
        }while(next_permutation(perm.begin(),perm.end()));
        return res;
    }else{
        if(assignedProb==j){
            return t[i][j];
        }
        vector<int>perm;
        for(int k=0;k<n;k++){
            if(k!=assignedProb){perm.push_back(k);}
        }
        int res=1e9;
        do{
            int time=t[i][assignedProb];
            for(int k=0;k<perm.size();k++){
                time+=t[i][perm[k]];
                if(perm[k]==j){
                    res=min(res,time);
                    break;
                }
            }
        }while(next_permutation(perm.begin(),perm.end()));
        return res;
    }
}

inline bool canFindOrders(){

    for(int i=0;i<n;i++){
        int assignedProb=-1;
        for(int j=0;j<n;j++){
            if(ass[j]==i){
                assignedProb=j;
                break;
            }
        }

        if(assignedProb==-1)return false;

        order[i][0]=assignedProb;
        int idx=0;
        for(int j=0;j<n;j++){
            if(j!=assignedProb){
                order[i][++idx]=j;
            }
        }
    }

    for(int j=0;j<n;j++){
        int team=ass[j];
        int teamTime=t[team][j];

        for(int i=0;i<n;i++){
            if(i==team){continue;}

            int minOtherTime=minTime(i,j);

            if(minOtherTime<=teamTime){return false;}
        }
    }

    return true;
}

inline bool solve(int problem){
    if(problem==n){
        return canFindOrders();
    }

    for(int team=0;team<n;team++){

        bool used=false;
        for(int j=0;j<problem;j++){
            if(ass[j]==team){
                used=true;
                break;
            }
        }
        if(used){continue;}

        ass[problem]=team;
        if(solve(problem+1))return true;
    }
    return false;
}

signed main(void){
    while(n=read()){
        if(n==0)return 0;

        t.assign(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                t[i][j]=read();
            }
        }

        ass.assign(n,-1);
        order.assign(n,vector<int>(n));

        if(solve(0)){
            printf("It's a perfect scoreboard!\n");
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    printf("%c",'A'+order[i][j]);
                }
                printf("\n");
            }
        }else{
            printf("Can't make a perfect scoreboard\n");
        }
    }
}
/*
3
1 2 3
2 3 1
3 2 1

5
1 2 3 4 5
2 3 4 5 6
5 1 2 3 4
6 7 1 1 2
9 6 3 2 4

2
1 1
2 2

4
50 300 300 300
1 50 5 100
100 100 100 1
1 30 30 100
*/
