#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, C;
    cin >> N >> C;
    map<int64_t, int64_t> events;
    for (int i = 0; i < N; i++) {
        int64_t a, b, c;
        cin >> a >> b >> c;
        events[a - 1] += c;
        events[b] -= c;
    }

    int64_t ans = 0, fee = 0, pre = 0;
    for (auto event: events) {
        ans += min(fee, C) * (event.first - pre);
        fee += event.second;
        pre = event.first;
    }

    cout << ans << endl;
}