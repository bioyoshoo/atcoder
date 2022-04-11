#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, M;
    cin >> N >> M;
    if (N > M) swap(N, M);

    int64_t ans = 0;
    if (N == 1) {
        if (M == 1) ans = 1;
        else ans = M - 2;
    }
    else {
        ans = (N - 2) * (M - 2);
    }

    cout << ans << endl;
}