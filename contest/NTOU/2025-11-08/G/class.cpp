#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<algorithm>

#define int long long
using namespace std;

const int MOD = 998244353;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

struct Matrix {
    int a[2][2];
    Matrix() {
        a[0][0] = a[1][1] = 1;
        a[0][1] = a[1][0] = 0;
    }
    Matrix(int a00, int a01, int a10, int a11) {
        a[0][0] = a00; a[0][1] = a01;
        a[1][0] = a10; a[1][1] = a11;
    }
    Matrix operator*(const Matrix& other) const {
        Matrix res;
        res.a[0][0] = (a[0][0] * other.a[0][0] + a[0][1] * other.a[1][0]) % MOD;
        res.a[0][1] = (a[0][0] * other.a[0][1] + a[0][1] * other.a[1][1]) % MOD;
        res.a[1][0] = (a[1][0] * other.a[0][0] + a[1][1] * other.a[1][0]) % MOD;
        res.a[1][1] = (a[1][0] * other.a[0][1] + a[1][1] * other.a[1][1]) % MOD;
        return res;
    }
};

Matrix matrixPower(Matrix base, int exp) {
    Matrix result;
    while(exp > 0) {
        if(exp & 1) result = result * base;
        base = base * base;
        exp >>= 1;
    }
    return result;
}

signed main(void){
    int n = read();

    if(n == 0) {
        write(1);
        putchar('\n');
        return 0;
    }
    if(n == 1) {
        write(1);
        putchar('\n');
        return 0;
    }

    // f(n) = f(n-1) + f(n-2) with f(0)=1, f(1)=1
    // Using matrix exponentiation: [f(n+1), f(n)]^T = M^n * [f(1), f(0)]^T
    // where M = [[1, 1], [1, 0]]
    Matrix fibMatrix(1, 1, 1, 0);
    Matrix result = matrixPower(fibMatrix, n);

    // M^n * [f(1), f(0)]^T = [f(n+1), f(n)]^T
    // So f(n) = result.a[1][0] * f(1) + result.a[1][1] * f(0)
    //         = result.a[1][0] * 1 + result.a[1][1] * 1
    //         = result.a[1][0] + result.a[1][1]
    int ans = (result.a[1][0] + result.a[1][1]) % MOD;

    write(ans);
    putchar('\n');
}
