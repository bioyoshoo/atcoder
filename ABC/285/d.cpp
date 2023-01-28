#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

bool DFS(Graph &G, vector<bool> &seen, int x, int s) {
    seen[x] = true;
    for (auto nx: G[x]) {
        if (nx == s) return true;
        if (seen[nx]) continue;
        if (DFS(G, seen, nx, s)) return true;
    }
    return false;
}

int main() {
    int N; cin >> N;
    vector<string> S(N), T(N);
    set<string> st;
    rep(i, N) {
        string s, t; cin >> s >> t;
        S[i] = s; T[i] = t;
        st.insert(s); st.insert(t);
    }
    
    map<string, int> char2int;
    int cnt = 0;
    for (auto s: st) {
        char2int[s] = cnt;
        cnt++;
    }

    int M = st.size();
    Graph G(M);

    rep(i, N) {
        int s = char2int[S[i]];
        int t = char2int[T[i]];
        G[s].push_back(t);
    }

    //　訪問済み
    vector<bool> seen(M, false);
    bool ans = true;
    rep(x, M) {
        if (seen[x]) continue;

        if (DFS(G, seen, x, x)) ans = false;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
