#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

int main() {
    int N, M; cin >> N >> M;
    vector<int> to(N), into(N);
    set<pair<int, int>> history;
    Graph G(N);
    rep(i, M) {
        // a < b
        int a, b; cin >> a >> b; a--; b--;

        if (history.count({a, b})) continue;
        G[a].push_back(b);
        to[a] += 1; into[b] += 1;
        history.insert({a, b});
    }

    int root = -1;
    int r_cnt = 0, t_cnt = 0, m_cnt = 0;
    bool flg = true;

    rep(i, N) {
        if (into[i] == 0 && to[i] == 1) {
            r_cnt += 1; root = i;
        }
        else if (into[i] == 1 && to[i] == 1) m_cnt += 1;
        else if (into[i] == 1 && to[i] == 0) t_cnt += 1;
        else flg = false;
    }

    if (r_cnt != 1) flg = false;
    if (m_cnt != N - 2) flg = false;
    if (t_cnt != 1) flg = false;

    if (!flg) {
        cout << "No" << endl;
        return 0;
    }
    
    vector<int> ans(N);
    int x = root;
    rep(i, N - 1) {
        ans[x] = i + 1;
        x = G[x][0];
    }
    ans[x] = N;

    cout << "Yes" << endl;
    rep(i, N) cout << ans[i] << " ";
    cout << endl;
}
