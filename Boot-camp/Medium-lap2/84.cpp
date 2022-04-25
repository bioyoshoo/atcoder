#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; i++) cin >> L.at(i);
    sort(L.begin(), L.end());

    int ans = 0;
    for (int a = 0; a < N; a++) {
        for (int b = a + 1; b < N; b++) {
            int idx = b + 1;
            if (idx >= N) continue;
            auto iter = L.begin() + idx;
            auto cand1 = lower_bound(iter, L.end(), L[a] + L[b]);
            auto cand2 = upper_bound(iter, L.end(), L[b] - L[a]);
            ans += cand1 - cand2;
        }
    }

    cout << ans << endl;
}