#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int ans = 0;
    vector<int> left(26, 0), right(26, 0);
    for (int i = 0; i < N; i++) {
        int idx = (int)(S[i] - 'a');
        right[idx]++;
    }

    for (int i = 0; i < N - 1; i++) {
        int idx = (int)(S[i] - 'a');
        left[idx]++; right[idx]--;

        int cond = 0;
        for (int i = 0; i < 26; i++) {
            if (left[i] != 0 && right[i] != 0) cond++;
        }

        ans = max(ans, cond);
    }

    cout << ans << endl;
}