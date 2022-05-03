#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }

    bool flag = true;
    int s = 0;
    if (N % 2 == 0) s = 1;
    for (; s <= N - 1; s += 2) {
        if (!mp.count(s)) flag = false;
        if (s == 0 && mp[0] != 1) flag = false;
        if (s != 0 && mp[s] != 2) flag = false;
    }

    int64_t ans;
    if (flag) {
        ans = 1;
        for (auto m: mp) ans = ans * m.second % mod;
    }
    else ans = 0;

    cout << ans << endl;
}