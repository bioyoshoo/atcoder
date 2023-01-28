#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ld INF = 1e10;

ld dist(ld x1, ld y1, ld x2, ld y2) {
    ld res = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    return res;
}

int main() {
    int N, M; cin >> N >> M;
    vector<ld> XN(N), YN(N), RN(N);
    rep(i, N) cin >> XN[i] >> YN[i] >> RN[i];
    vector<ld> XM(M), YM(M);
    rep(i, M) cin >> XM[i] >> YM[i];

    ld min_dist = INF;
    if (M != 0) {
        // N-M
        rep(i, N) {
            rep(j, M) {
                ld d = dist(XN[i], YN[i], XM[j], YM[j]) - RN[i];
                min_dist = min(min_dist, d);
            }
        }

        rep(i, M) {
            rep(j, M) {
                if (i == j) continue;
                ld d = dist(XM[i], YM[i], XM[j], YM[j]) / 2;
                min_dist = min(min_dist, d);
            }
        }    
    }
    else {
        rep(i, N) min_dist = min(min_dist, RN[i]);
    }
    
    cout << fixed << setprecision(15);
    cout << min_dist << endl;
}