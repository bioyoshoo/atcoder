#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;

    vector<int> P(N);
    P[0] = -1;
    for (int i = 1; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }

    int ans = 0;
    int i = N - 1;
    while (P[i] != -1) {
        ans++;
        i = P[i];
    }
    cout << ans << endl;
}