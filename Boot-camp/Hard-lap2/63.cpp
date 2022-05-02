#include <bits/stdc++.h>
using namespace std;

int n_keta(int64_t n) {
    return to_string(n).size();
}

set<int> D;
vector<int64_t> candidate;
void DFS(int64_t n) {
    if (n_keta(n) >= 6) return;
    candidate.push_back(n);

    for (int i = 0; i < 10; i++) {
        if (n == 0 && i == 0) continue;
        if (D.count(i)) continue;
        DFS(10 * n + i);
    }
}

int main() {
    int64_t N, K;
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int d; cin >> d;
        D.insert(d);
    }

    DFS(0);
    sort(candidate.begin(), candidate.end());
    int64_t ans = *lower_bound(candidate.begin(), candidate.end(), N);
    cout << ans << endl;
}