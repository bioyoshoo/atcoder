#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
<<<<<<< HEAD
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
const ld INF = 1e10;

ld dist(ld x1, ld y1, ld x2, ld y2) {
    ld res = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    return res;
=======
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
>>>>>>> bc9a185f6f7513da0bc977790ba6c67c254988b0
}

int main() {
    int N, M; cin >> N >> M;
<<<<<<< HEAD
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
=======
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
>>>>>>> bc9a185f6f7513da0bc977790ba6c67c254988b0
