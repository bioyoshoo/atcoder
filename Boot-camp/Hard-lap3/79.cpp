#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K; cin >> N >> K;
    string S; cin >> S;
    vector<pair<char, int>> V;
    for (int i = 0; i < N;) {
        int j = i;
        while (j < N && S[i] == S[j]) j++;
        V.push_back({S[i], j - i});
        i = j;
    }

    int n = V.size();
    
    vector<int> C(n);
    rep(i, n) C[i] = V[i].second;
    rep(i, n - 1) C[i + 1] += C[i];

    int ans = -1;
    rep(i, n) {
        int j;
        if (V[i].first == '1') j = min(i + 2 * K, n - 1);
        else j = min(i + 2 * K - 1, n - 1);

        if (i == 0) ans = max(ans, C[j]);
        else ans = max(ans, C[j] - C[i - 1]);
    }
    cout << ans << endl;
}