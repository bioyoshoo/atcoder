#include <bits/stdc++.h>
using namespace std;

vector<int64_t> common_divisers(int64_t n) {
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
    int64_t N, M;
    cin >> N >> M;

    vector<int64_t> V = common_divisers(M);
    int64_t ans;
    for (auto n: V) if (n * N <= M) ans = n;
    
    cout << ans << endl;
}