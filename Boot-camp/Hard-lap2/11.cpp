#include <bits/stdc++.h>
using namespace std;

vector<int64_t> prime_factors(int64_t n) {
    vector<int64_t> res;
    res.push_back(1);
    for (int64_t a = 2; a * a <= n; a++) {
        if (n % a != 0) continue;
        while (n % a == 0) n /= a;
        res.push_back(a);
    }
    if (n > 1) res.push_back(n);
    return res;
}

int main() {
    int64_t A, B;
    cin >> A >> B;

    int64_t n = gcd(A, B);
    vector<int64_t> ans = prime_factors(n);

    cout << ans.size() << endl;
}