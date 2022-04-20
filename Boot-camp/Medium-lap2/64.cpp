#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int64_t, int64_t> mp;
    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        mp[a]++;
    }

    int64_t ans = 0;
    for (auto m: mp) {
        if (m.first > m.second) ans += m.second;
        else if (m.first < m.second) ans += m.second - m.first;
    }

    cout << ans << endl;
}