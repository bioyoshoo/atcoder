#include <bits/stdc++.h>
using namespace std;

int score(char c, int R, int S, int P) {
    if (c == 'r') return P;
    else if (c == 'p') return S;
    else return R;
}

int main() {
    int N, K, R, S, P;
    string T;
    cin >> N >> K >> R >> S >> P >> T;

    int64_t ans = 0;
    for (int k = 0; k < K; k++) {
        string s;
        for (int i = k; i < N; i += K) s.push_back(T.at(i));
        int n = s.size();
        bool last;
        for (int i = 0; i < n; i++) {
            if (i == 0) ans += score(T[0], R, S, P), last = true;
            else if (T[i - 1] != T[i]) last = true, ans += score(T[i], R, S, P);
            else {
                if (!last) ans += score(T[i], R, S, P), last = true;
                else last = false;
            }
        }
    }

    cout << ans << endl;
}