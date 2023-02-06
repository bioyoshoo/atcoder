#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

vector<string> V;
map<string, int> ans;

// S 文字集合, k 見ている文字のindex
void LCP(vector<int> S, int i) {
    int siz = S.size();
    if (siz == 0) return;
    else if (siz == 1) {
        ans[V[S[0]]] = i - 1;
        return;
    }

    // 末尾の文字で分類
    map<char, vector<int>> Next;
    rep(j, siz) {
        string seq = V[S[j]];
        int n = seq.size();

        if (i >= n) {
            ans[seq] = n;
            continue;
        }

        Next[seq[i]].push_back(S[j]);
    }

    for (auto [ignore, N]: Next) {
        LCP(N, i + 1);
    }
}

int main() {
    int N; cin >> N;
    V.resize(N);
    rep(i, N) cin >> V[i];

    vector<int> S; rep(i, N) S.push_back(i);
    LCP(S, 0);

    rep(i, N) cout << ans[V[i]] << endl;
}
