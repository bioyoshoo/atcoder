#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ans = 0;
    for (int r = 0; r <= N / R; r++) {
        for (int b = 0; b <= N / B; b++) {
            int g = N - r * R - b * B;

            if (g >= 0 && g % G == 0) ans++;
        }
    }

    cout << ans << endl;
}