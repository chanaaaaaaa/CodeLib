#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-ferun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-function-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

/* Self Define Const */

#include <iostream>
#include <string>
#include <unordered_map>

#define LL long long
using namespace std;

/* Programing area */

// ABC 208 E - Digit Products

// opt：mul is only 0 or 2^a*3^b*5^c*7^d, act.num = O((log K)^4)
// dp[start][small][prod]=cnt

//N=123456789

void solve() {
    string N;
    LL K;
    cin >> N >> K;

    LL INF = K + 1;
    unordered_map<LL, LL> dp;  // product , count
    LL eq_prod = 1;            // the product of all digits(char &c:s)

    bool f=true;        //isfirst digit ?
    for (char &c:N) {
        int digit = c - '0';
        unordered_map<LL, LL> nxt;

        // (1) less -> less: 已小於 N 的前綴，可選 0~9
        //                   曾在某項出現過 ${d} < ${digit}
        for (auto& [prod, val] : dp) {
            for (int d = 0; d <= 9; d++) {
                LL nxt_prod = min(INF, prod * d);
                nxt[nxt_prod] += val;
            }
        }

        // (2) equal -> less: 前綴等於 N，此位選小於 digit 的數
        //                    before this step for all ${d} == ${digit}
        //                    in this step get the ${d} < ${digit}
        for (int d = 0; d < digit; d++) {
            if (f && d == 0) continue;  //the first digit can't be 0
            LL nxt_prod = min(INF, eq_prod * d);
            nxt[nxt_prod] += 1;         //eq_prod.cnt always 1
        }
        
        // (3) equal -> equal: 繼續匹配 N
        //                     only need to make next eq_prod
        //                     if eq_prod is a sol. for K 
        //                        res++ after the result counting
        eq_prod = min(INF, eq_prod * digit);

        // (4) 0...0d 形式：前 i 位全 0，此位選 1~9（單一位數等）
        //                 get [all zero] -> [less]
        //                 the count of [all zero] is 0
        //                 but the act of {less} is special ,so make the count of {less} +1
        if (!f) {
            for (int d = 1; d <= 9; d++) {
                LL nxt_prod = min(INF, (LL)d);
                nxt[nxt_prod] += 1;
            }
        }
        // (5) no need to discuss any {all zero} -> {all zero}

        dp = move(nxt);
        f=false;
    }

    LL answer = 0;

    // 統計乘積 <= K 的數量
    for (auto& [prod, val] : dp) {
        if (prod <= K) answer += val;
    }
    if (eq_prod <= K) answer += 1;

    cout << answer << '\n';
}

signed main() {
    //IO
    solve();
    system("pause");
    return 0;
}
