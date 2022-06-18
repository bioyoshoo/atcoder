#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<pair<int, int>> V(N);
    rep(i, N) cin >> V[i].first >> V[i].second;
    sort(V.begin(), V.end());

    pair<int, int> ans;
    int end = -1;
    rep(i, N) {
        int start = V[i].first;
        int cand_end = V[i].second;

        if (end < start) {
            if (end != -1) cout << ans.first << " " << ans.second << endl;
            ans.first = start;
        }
        
        if (end < cand_end) {
            end = cand_end;
            ans.second = cand_end;
        }
        
        if (i == N - 1) cout << ans.first << " " << ans.second << endl;
    }
}