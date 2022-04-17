#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
<<<<<<< HEAD
    int n = S.size();

    set<char> s;
    for (char c: S) s.insert(c);

    int ans = 0;
    for (char c: s) {
        
        int pre_idx = -1;
        for (int i = 1; i < n; i++) {
            if (S[i] == c) {
                ans = max(ans, i - pre_idx - 1);
                pre_idx = i;
            }
            else if (i == n - 1) ans = max(ans, i - pre_idx);
        }
=======
    int64_t N = S.size();

    int64_t ans = N * (N - 1);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'U') ans += i;
        else if (S[i] == 'D') ans += N - 1 - i;
>>>>>>> 90b983a3b7ed233c62f00ab424f77a6514f7372a
    }

    cout << ans << endl;
}