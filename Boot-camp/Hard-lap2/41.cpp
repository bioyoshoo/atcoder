#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;

    int64_t ans;
    if (K % 2 != 0) ans = pow(N / K, 3);
    else {
        int n = K / 2;
        ans = pow(N / n, 3);
    }

    cout << ans << endl;
}