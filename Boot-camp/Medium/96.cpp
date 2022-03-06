#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> broken(N + 1, false);
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        broken.at(a) = true;
    }

    vector<int64_t> dp(N + 1, 0);
    dp.at(0) = 1;

    for (int i = 0; i <= N; i++) {
        if (broken.at(i)) continue;

        if (i - 2 >= 0) dp.at(i) += dp.at(i - 2);
        if (i - 1 >= 0) dp.at(i) += dp.at(i - 1);

        dp.at(i) %= mod;
    }

    cout << dp.at(N) << endl;
}
