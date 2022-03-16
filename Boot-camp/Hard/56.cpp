#include <bits/stdc++.h>
using namespace std;

int64_t comb(int64_t n, int64_t k) {
    int64_t num = 1, deno = 1;
    for (int i = n - k + 1; i <= n; i++) num *= i;
    for (int i = 1; i <= k; i++) deno *= i;
    return num / deno;
}
int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N), Cum(N + 1, 0);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 1; i < N + 1; i++) Cum.at(i) += Cum.at(i - 1) + A.at(i - 1);

    sort(Cum.begin(), Cum.end());

    int64_t ans = 0;
    for (int i = 0; i < N + 1;) {
        int ser = 1;
        while (i + ser < N + 1 && Cum.at(i) == Cum.at(i + ser)) ser++;
        ans += comb(ser, 2);
        i += ser;
    }

    cout << ans << endl;
}