#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, S;
    cin >> K >> S;

    int64_t ans = 0;
    for (int x = 0; x <= K; x++) {
        for (int y = x; y <= K; y++) {
            int z = S - x - y;
            if (z < y || z > K) continue;

            if (x == y && y == z) ans += 1;
            else if (x == y || y == z) ans += 3;
            else ans += 6;
        }
    }

    cout << ans << endl;
}