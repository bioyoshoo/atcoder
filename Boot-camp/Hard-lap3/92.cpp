#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, M; cin >> N >> M;
    vector<int> V(N);
    rep(i, M) {
        int a, b; a--; b--;
        cin >> a >> b;
        V[a]++; V[b]++;
    }
    bool ans = true;
    for (int i = 0; i < N; i++) if (V[i] % 2 != 0) ans = false;
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}