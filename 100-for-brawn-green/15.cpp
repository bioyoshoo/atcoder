#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<pair<ld, ld>> V(N);
    rep(i, N) {
        ld x, y; cin >> x >> y;
        V[i] = {x, y};
    }

    ld ans = 0;
    sort(V.begin(), V.end());
    do {
        ld dist = 0;
        for (int x = 0; x < N - 1; x++) {
            int x1, x2, y1, y2;
            tie(x1, y1) = V[x];
            tie(x2, y2) = V[x + 1];
            dist += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        }
        ans += dist;
    } while (next_permutation(V.begin(), V.end()));

    ld n = 1;
    for (ld x = 1; x <= N; x++) n *= x;
    ans /= n;
    cout << fixed << setprecision(12);
    cout << ans << endl;
}