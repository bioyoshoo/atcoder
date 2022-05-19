#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;

    int k;
    for (int n = 1; n <= N; n++) {
        if (n * n <= N) k = n;
        else break;
    }

    int ans = 2 * N;
    for (int a = 1; a <= k; a++) {
        for (int b = k; b <= N; b++) {
            if (N < a * b) continue;
            int cand = (b - a) + N - a * b;
            ans = min(ans, cand);
        }
    }
    cout << ans << endl;
}