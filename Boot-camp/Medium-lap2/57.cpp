#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<string, int64_t> mp;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        mp[s]++;
    }

    int64_t ans = 0;
    for (auto [x, y]: mp) {
        if (y == 1) continue;
        ans += y * (y - 1) / 2;
    }

    cout << ans << endl;
}