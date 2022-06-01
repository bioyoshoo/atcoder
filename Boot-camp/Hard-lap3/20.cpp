#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

string padding(int n) {
    string S = to_string(n);
    int siz = S.size();
    rep(i, 6 - siz) S = '0' + S;
    return S;
}

int main() {
    int N, M; cin >> N >> M;
    vector<vector<pair<ll, ll>>> City(N);
    rep(i, M) {
        ll p, y; cin >> p >> y; p--;
        City[p].push_back({y, i});
    }
    vector<string> ans(M);
    rep(i, N) {
        int n = City[i].size();
        if (n == 0) continue;
        sort(City[i].begin(), City[i].end());
        string pref = padding(i + 1);
        rep(j, n) {
            int city_id = City[i][j].second;
            string id = padding(j + 1);
            ans[city_id] = pref + id;
        }
    }
    for (int i = 0; i < M; i++) cout << ans[i] << endl;
}