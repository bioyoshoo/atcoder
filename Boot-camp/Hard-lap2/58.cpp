#include <bits/stdc++.h>
using namespace std;

vector<int64_t> common_divisors(int64_t n) {
    vector<int64_t> res;
    for (int64_t a = 1; a * a <= n; a++) {
        if (n % a == 0) {
            res.push_back(a);
            if (a != n / a) res.push_back(n / a);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> V = common_divisors(N);

    int64_t ans = 0;
    for (auto v: V) {
        int64_t m = N / v - 1;
        if (m == 0) continue;
        if (N / m == N % m) ans += m;
    }
    cout << ans << endl;
}