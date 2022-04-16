#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int64_t N = S.size();

    int64_t ans = N * (N - 1);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'U') ans += i;
        else if (S[i] == 'D') ans += N - 1 - i;
    }

    cout << ans << endl;
}