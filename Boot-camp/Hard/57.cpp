#include <bits/stdc++.h>
using namespace std;

vector<int64_t> enum_divesors(int64_t n) {
    vector<int64_t> res;
    for (int64_t i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int64_t N;
    cin >> N;

    vector<int64_t> res = enum_divesors(N);

    int64_t ans = 0;
    for (int64_t k: res) {
        int64_t m = N / k - 1;
        if (m >= 2 && m + 1 - k >= 2) ans += m;
    }

    cout << ans << endl;
}