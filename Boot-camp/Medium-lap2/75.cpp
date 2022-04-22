#include <bits/stdc++.h>
using namespace std;

int score(char hand, int R, int S, int P) {
    if (hand == 'r') return P;
    else if (hand == 's') return R;
    else return S;
}

int main() {
    int N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;

    int64_t ans = 0;
    for (int k = 0; k < K; k++) {
        bool last = true;
        for (int i = k; i < N; i += K) {
            if (i - K >= 0 && T[i - K] == T[i] && last) last = false;
            else ans += score(T[i], R, S, P), last = true; 
        }
    }

    cout << ans << endl;
}