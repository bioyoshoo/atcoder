#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;

    int64_t n = 1, sum = 0;
    for (; n <= N; n++) {
        sum += n;
        if (sum >= N) break;
    }

    int64_t m = sum - N;
    for (int64_t i = 1; i <= n; i++) {
        if (m == i) continue;
        cout << i << endl;
    }
}