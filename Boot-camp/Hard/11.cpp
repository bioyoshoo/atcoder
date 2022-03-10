#include <bits/stdc++.h>
using namespace std;

set<int64_t> prime_factorize(int64_t n) {
    set<int64_t> ans;

    for (int64_t a = 2; a * a <= n; a++) {
        int64_t exp = 0;
        while (n % a == 0) {
            exp++;
            n /= a;
        }
        if (exp > 0) ans.insert(a);
    }
    if (n > 1) ans.insert(n);
    return ans;
}

int main() {
    int64_t A, B;
    cin >> A >> B;

    set<int64_t> A_factorize, B_factorize;
    vector<int64_t> ans;

    A_factorize = prime_factorize(A);
    B_factorize = prime_factorize(B);
    for (int64_t a: A_factorize) {
        if (B_factorize.count(a)) ans.push_back(a);
    }

    cout << ans.size() + 1 << endl;
}