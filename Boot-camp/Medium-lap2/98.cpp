#include <bits/stdc++.h>
using namespace std;
using vpii = vector<pair<int64_t, int64_t>>;

vpii primary_factorize(int64_t n) {
    vpii ans;
    for (int64_t a = 2; a * a <= n; a++) {
        int64_t power = 0;
        while (n % a == 0) {
            n /= a;
            power++;
        }
        ans.push_back({a, power});
    }
    if (n > 1) ans.push_back({n, 1});
    return ans;
}

int main() {
    int64_t N, P;
    cin >> N >> P;

    int64_t ans = 1;
    vpii factorize = primary_factorize(P);
    for (auto factor: factorize) {
        int64_t n, p;
        tie(n, p) = factor;
        ans *= pow(n, p / N);
    }

    cout << ans << endl;
}