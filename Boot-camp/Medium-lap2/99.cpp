#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, M, K;
    cin >> N >> M >> K;

    bool ans = false;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            int64_t black = (N - i) * j + (M - j) * i;
            if (black == K) {
                ans = true;
                goto OUT;
            }
        }
    }
OUT:
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}