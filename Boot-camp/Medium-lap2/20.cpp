#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int64_t, int> mp;
    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        mp[a]++;
    }

    int64_t ans = 0;
    for (auto p: mp) {
        if (p.second % 2 != 0) ans++;
    }

    cout << ans << endl;
}