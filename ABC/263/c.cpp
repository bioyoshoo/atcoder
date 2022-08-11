#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)


int main() {
    int N, M; cin >> N >> M;

    vector<vector<int>> prev;
    rep(i, M) prev.push_back({i + 1});

    for (int i = 1; i < N; i++) {
        vector<vector<int>> nex;
        for (auto v: prev) {
            int x = v.back();
            for (int j = x + 1; j <= M; j++) {
                vector<int> v2 = v;
                v2.push_back(j);
                nex.push_back(v2);
            }
        }
        prev = nex;
    }

    for (auto a: prev) {
        for (auto b: a) cout << b << " ";
        cout << endl;
    }
}