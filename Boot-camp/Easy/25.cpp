#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> P(N), Q(N), R(N);
    rep(i, N) R[i] = i + 1;
    rep(i, N) cin >> P[i];
    rep(i, N) cin >> Q[i];

    int cnt = 0;
    int a = -1, b = -1;
    do {
        cnt++;
        bool flag_a = true, flag_b = true;;
        rep(i, N) {
            if (P[i] != R[i]) flag_a = false;
            if (Q[i] != R[i]) flag_b = false;
        }
        if (flag_a) a = cnt;
        if (flag_b) b = cnt;
    } while (next_permutation(R.begin(), R.end()));

    cout << abs(a - b) << endl;
}