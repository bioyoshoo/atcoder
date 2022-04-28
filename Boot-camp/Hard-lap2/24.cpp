#include <bits/stdc++.h>
using namespace std;
using interval = pair<int64_t, int64_t>;

bool cmp(const interval &a, const interval &b) {
    return a.second < b.second;
}

int main() {
    int64_t N;
    cin >> N;
    vector<interval> V(N);
    for (int i = 0; i < N; i++) {
        int64_t x, l;
        cin >> x >> l;
        V.at(i) = {x - l, x + l};
    }
    sort(V.begin(), V.end(), cmp);

    int64_t cur = -1e10;
    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        int64_t s, e;
        tie(s, e) = V.at(i);
        if (cur <= s) {
            cur = e;
            ans++;
        }
    }

    cout << ans << endl;
}