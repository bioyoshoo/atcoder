#include <bits/stdc++.h>
using namespace std;

int64_t func(int64_t n) {
    if (n <= 0) return 0;
    
    int64_t res = 0;
    for (int64_t k = 0; k < 40; k++) {
        int64_t loop = (1LL << (k + 1));
        int64_t cnt = ((n + 1) / loop) * (loop / 2);
        cnt += max((int64_t)0, ((n + 1) % loop) - loop / 2);

        if (cnt % 2 == 1) res += (1LL << k);
        }
    return res;
}

int main() {
    int64_t a, b;
    cin >> a >> b;

    int64_t ans = func(a - 1) ^ func(b);
    cout << ans << endl;
}