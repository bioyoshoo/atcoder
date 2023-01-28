#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    string S; cin >> S;

    vector<int> R(N - 1), L(N - 1);
    rep(i, N - 1) if (S[i] == 'A') R[i] = 1;
    rep(i, N - 1) if (S[i] == 'B') L[i] = 1;

    for (int i = 1; i < N - 1; i++) if (R[i] == 1 && R[i - 1] != 0) R[i] += R[i - 1];
    for (int i = N - 3; i >= 0; i--) if (L[i] == 1 && L[i + 1] != 0) L[i] += L[i + 1];

    vector<int> VR(N), VL(N);
    rep(i, N - 1) if (R[i] != 0) {
        VR[i] = R[i]; VR[i + 1] = R[i] + 1;
    }
    rep(i, N - 1) if (L[i] != 0) {
        VL[i] = L[i] + 1; VL[i + 1] = L[i];
    }

    int ans = 0;
    rep(i, N) ans += max(VR[i], VL[i]);
    cout << ans << endl;
}
