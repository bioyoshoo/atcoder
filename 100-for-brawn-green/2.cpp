#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int prime_facotrize(int n) {
    if (n == 1) return 1;

    vector<int> res;
    for (int a = 2; a * a <= n; a++) {
        if (n % a != 0) continue;
        int exp = 0;
        while (n % a == 0) {
            exp++;
            n /= a;
        }
        res.push_back(exp);
    }
    if (n > 1) res.push_back(1);
    int ans = 1;
    for (auto r: res) ans *= (r + 1);
    return ans;
}

int main() {
    int N; cin >> N;
    int ans = 0;
    for (int x = 1; x <= N; x += 2) {
        int n = prime_facotrize(x);
        if (n == 8) ans++;
    }
    cout << ans << endl;
}