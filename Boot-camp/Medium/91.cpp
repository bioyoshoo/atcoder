#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, S;
    cin >> K >> S;

    int ans = 0, max_range_x = min(K, S);
    for (int x = 0; x <= max_range_x; x++) {
        int max_range_y = min(x + K, S);
        for (int y = x; y <= max_range_y; y++) {
            if (S - y <= K) ans++;
        }
    }
    cout << ans << endl;
}