#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    int64_t begin_b = 0, end_a = 0, both = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        int n = S.size();
        if (S[0] == 'B' && S[n - 1] == 'A') both++;
        else if (S[0] == 'B') begin_b++;
        else if (S[n - 1] == 'A') end_a++;

        for (int j = 1; j < n; j++) {
            if (S[j - 1] == 'A' && S[j] == 'B') ans++;
        }
    }

    ans += max((int64_t)0, both - 1);

    if (begin_b == 0 && end_a == 0) cout << ans << endl;
    else {
        if (both > 0) ans++;
        ans += min(begin_b, end_a);
        cout << ans << endl;
    }
}