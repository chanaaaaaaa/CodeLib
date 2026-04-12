#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;

    while(t--){
        cin >> n;
        vector<int> vec(n);
        for(int &i : vec)
            cin >> i;

        sort(vec.begin(), vec.end());
        int mid = vec[n / 2], ans = 0;

        for(int &i : vec)
            ans += abs(mid - i);

        cout << ans << '\n';
    }
    return 0;
}
