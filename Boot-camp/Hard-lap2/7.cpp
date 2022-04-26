#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, M;
    cin >> N >> M;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    sort(A.begin(), A.end());
    vector<pair<int64_t, int64_t>> V(M);
    for (int i = 0; i < M; i++) {
        int64_t b, c;
        cin >> b >> c;
        V.at(i) = {c, b};
    }
    sort(V.rbegin(), V.rend());

    vector<int64_t> changes;
    for (auto v: V) {
        int64_t b, c;
        tie(c, b) = v;
        for (int i = 0; i < b; i++) changes.push_back(c);
        if ((int)changes.size() >= N) break;
    }

    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        if (i + 1 <= (int)changes.size()) {
            if (A[i] < changes[i]) ans += changes[i];
            else ans += A[i];
        }
        else ans += A[i];
    }

    cout << ans << endl;
}