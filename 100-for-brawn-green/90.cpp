#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main() {
    int N, M; cin >> N >> M;
    vector<ld> X1(N), Y1(N), R(N), X2(M), Y2(M);
    rep(i, N) cin >> X1[i] >> Y1[i] >> R[i];
    rep(i, M) cin >> X2[i] >> Y2[i];

    ld cand1 = 1e5;
    rep(i, M) rep(j, M) {
        if (i == j) continue;
        cand1 = min(cand1, dist(X2[i], Y2[i], X2[j], Y2[j]) / 2);
    }
    
    ld cand2 = 1e5;
    if (M == 0) {
        rep(i, N) cand2 = min(cand2, R[i]);
    }
    else {
        rep(i, N) rep(j, M) {
            cand2 = min(cand2, dist(X1[i], Y1[i], X2[j], Y2[j]) - R[i]);
        }
    }
    
    cout << fixed << setprecision(15);
    cout << min(cand1, cand2) << endl;
}
