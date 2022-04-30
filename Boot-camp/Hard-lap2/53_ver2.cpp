#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int64_t, int64_t>> V(N);
    for (int i = 0; i < N; i++) {
        int64_t x, y; cin >> x >> y;
        V.at(i) = {x, y};
    }

    int ans;
    if (N == 1) ans = 1;
    else {
        ans = 1000;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                int64_t p = V[j].first - V[i].first, q = V[j].second - V[i].second;

                int cnt = 0;
                for (int x1 = 0; x1 < N; x1++) {
                    for (int x2 = 0; x2 < N; x2++) {
                        if (x1 == x2) continue;
                        if (p == V[x2].first - V[x1].first && q == V[x2].second - V[x1].second) cnt++;
                    }
                }
                ans = min(ans, N - cnt);
            }
        }
    }

    cout << ans << endl;
}