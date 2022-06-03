#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint1000000007;

vector<pair<int, int>> prime_factorize(int n) {
    vector<pair<int, int>> res;
    for (int a = 2; a * a <= n; a++) {
        if (n % a != 0) continue;
        int exp = 0;
        while (n % a == 0) {
            exp++;
            n /= a;
        }
        res.push_back({a, exp});
    }
    if (n > 1) res.push_back({n, 1});
    return res;
}

int main() {
    int N; cin >> N;
    vector<int> cnt(N + 1);
    for (int n = 1; n <= N; n++) {
        vector<pair<int, int>> res = prime_factorize(n);
        for (auto r: res) cnt[r.first] += r.second;
    }
    mint ans = 1;
    for (int i = 1; i <= N; i++) if (cnt[i] > 0) ans *= cnt[i] + 1;
    cout << ans.val() << endl;
}