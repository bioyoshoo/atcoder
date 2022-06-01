#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using Graph = vector<vector<int>>;

int main() {
    int N; cin >> N;
    int x, y; cin >> x >> y; x--; y--;
    
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        G[i].push_back(i + 1);
        G[i + 1].push_back(i);
    }
    G[x].push_back(y); G[y].push_back(x);

    vector<int> ans(N - 1);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int d = abs(i - x) + 1 + abs(y - j);
            int dist = min(j - i, d);
            ans[dist - 1]++;
        }
    }
    for (int i = 0; i < N - 1; i++) cout << ans[i] << endl;
}