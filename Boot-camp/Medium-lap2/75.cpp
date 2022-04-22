#include <bits/stdc++.h>
using namespace std;

<<<<<<< HEAD
int score(char c, int R, int S, int P) {
    if (c == 'r') return P;
    else if (c == 'p') return S;
    else return R;
=======
int score(char hand, int R, int S, int P) {
    if (hand == 'r') return P;
    else if (hand == 's') return R;
    else return S;
>>>>>>> 2bc1f3993e19d16e69af80a063f3c285c9aba476
}

int main() {
    int N, K, R, S, P;
<<<<<<< HEAD
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
=======
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;

    int64_t ans = 0;
    for (int k = 0; k < K; k++) {
        bool last = true;
        for (int i = k; i < N; i += K) {
            if (i - K >= 0 && T[i - K] == T[i] && last) last = false;
            else ans += score(T[i], R, S, P), last = true; 
>>>>>>> 2bc1f3993e19d16e69af80a063f3c285c9aba476
        }
    }

    cout << ans << endl;
}