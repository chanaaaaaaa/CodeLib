#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
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
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline bool check_mod(const string& S, int m) {
    int rem = 0;
    for (char c : S) {
        rem = (rem * 10 + (c - '0')) % m;
    }
    return rem == 0;
}

inline int get_last_n(const string& S, int n) {
    int res = 0,p = 1,len = S.length();
    for (int i = 0; i < n && i < len; ++i) {
        res += (S[len - 1 - i] - '0') * p;
        p *= 10;
    }
    return res;
}

inline void solve() {
    string S;
    int N, tmp;
    if (!(cin >> S >> N)) return;

    bool div[13] = {false};
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        if (tmp <= 12) div[tmp] = true;
    }

    if(div[12]){
        div[6]=false;
        div[4]=true;
        div[3]=true;
    }
    if(div[6]){
        div[2]=true;
        div[3]=true;
        div[6]=false;
    }
    if(div[10]){
        div[5]=false;
        div[2]=false;
    }
    if(div[9]){
        div[3]=false;
    }
    if(div[8]){
        div[4]=false;
        div[2]=false;
    }
    if(div[4]){
        div[2]=false;
    }
    if(div[8]&&div[9]){
        div[6]=false;
    }

    bool is_wonderful = true;

    for (int i = 2; i <= 12; ++i) {
        if (!div[i]) continue;

        bool current_ok = true;
        switch (i) {
            case 2:  if (get_last_n(S, 1) % 2 != 0) current_ok = false; break;
            case 3:  if (!check_mod(S, 3)) current_ok = false; break;
            case 4:  if (get_last_n(S, 2) % 4 != 0) current_ok = false; break;
            case 5:  if (get_last_n(S, 1) % 5 != 0) current_ok = false; break;
            case 6:  if (!check_mod(S, 6)) current_ok = false; break;
            case 7:  if (!check_mod(S, 7)) current_ok = false; break;
            case 8:  if (get_last_n(S, 3) % 8 != 0) current_ok = false; break;
            case 9:  if (!check_mod(S, 9)) current_ok = false; break;
            case 10: if (get_last_n(S, 1) % 10 != 0) current_ok = false; break;
            case 11: if (!check_mod(S, 11)) current_ok = false; break;
            case 12: if (!check_mod(S, 12)) current_ok = false; break;
        }

        if (!current_ok) {
            is_wonderful = false;
            break;
        }
    }

    cout << S << " - " << (is_wonderful ? "Wonderful." : "Simple.") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while (T--) {
        solve();
    }
    return 0;
}
