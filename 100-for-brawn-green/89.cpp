#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n; cin >> n;
    vector<int> T(n);
    rep(i, n) cin >> T[i];

    vector<int> V;
    for (int i = 0; i < n;) {
        int j = i + 1;
        int c = T[i];
        while (j < n && T[j] == 1 - c) {
            j++;
            c = 1 - c;
        }
        V.push_back(j - i);

        i = j;
    }
    
    int m = V.size();
    if (m == 1) cout << V[0] << endl;
    else if (m == 2) cout << V[0] + V[1] << endl;
    else {
        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (i + 2 < m) {
                ans = max(ans, V[i] + V[i + 1] + V[i + 2]);
            }
        }
        cout << ans << endl;
    }
}
