#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    int64_t ans = lcm(N, M);
    int64_t jump = lcm(ans / N, ans / M);
    bool flag = true;
    for (int64_t i = 0; i < ans; i += jump) {
        if (S.at(i * N / ans) != T.at(i * M / ans)) flag = false;
    }

    if (flag) cout << ans << endl;
    else cout << -1 << endl;
}