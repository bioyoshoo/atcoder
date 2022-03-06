#include <bits/stdc++.h>
using namespace std;

vector<pair<int64_t, int64_t>> prime_factorize(int64_t n) {
    vector<pair<int64_t, int64_t>> res;
    for (int64_t a = 2; a * a <= n; a++) {
        if (n % a != 0) continue;
        
        int64_t ex = 0;
        while (n % a == 0) {
            ex++;
            n /= a;
        }
        res.push_back({ a, ex });
    }
    if (n != 1) res.push_back({ n, 1 });
    return res;
}

int main() {
    int64_t N, P;
    cin >> N >> P;

    vector<pair<int64_t, int64_t>> P_factorize = prime_factorize(P);

    int64_t ans = 1;
    for (auto p: P_factorize) {
        int64_t f, ex;
        f = p.first;
        ex = p.second / N;
        ans *= pow(f, ex);
    }

    cout << ans << endl;
}