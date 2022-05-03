#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;

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
    int N;
    cin >> N;
    map<int, int> mp;
    for (int n = 2; n <= N; n++) {
        vector<pair<int, int>> res = prime_factorize(n);
        for (auto r: res) mp[r.first] += r.second;
    }

    int64_t ans = 1;
    for (auto m: mp) ans = ans * (m.second + 1) % mod;
    
    cout << ans << endl;
}