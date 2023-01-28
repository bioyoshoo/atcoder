#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> P(N); rep(i, N) cin >> P[i];

    vector<int> used(N + 1, true);
    vector<int> ans;
    for (int s = N - 1; s >= 0; s--) {
        int a = -1;
        for (int t = N; t >= 1; t--) {
            if (!used[t] && P[s] > t) {
                a = t;
                break;
            }
        }

        used[P[s]] = false;
        if (a == -1) continue;

        vector<int> cand;
        for (int i = 0; i < s; i++) cand.push_back(P[i]);
        cand.push_back(a);
        for (int v = N; v >= 1; v--) {
            if (!used[v] && v != a) cand.push_back(v);
        }

        ans = cand;
        break;
    }
    for (auto c: ans) cout << c << " ";
    cout << endl;
}
