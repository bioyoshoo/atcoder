#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

vector<pair<int, int>> prime_factorize(int n) {
    vector<pair<int, int>> res;
    for (int a = 2; a * a <= n; a++) {
        if (n % a != 0) continue;

        int exp = 0;
        while (n % a == 0) {
            n /= a;
            exp++;
        }

        res.push_back({a, exp});
    }

    if (n > 1) res.push_back({n, 1});
    
    return res;
}

int main() {
    int n; cin >> n;

    vector<pair<int, int>> res = prime_factorize(n);

    cout << n << ":";
    for (auto r: res) {
        rep(i, r.second) cout << " " << r.first;
    }
    cout << endl;
}