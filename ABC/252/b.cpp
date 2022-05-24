#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> A(N);
    set<int> B;
    rep(i, N) {
        int a;
        cin >> a;
        A.at(i) = {a, i};
    }
    rep(i, K) {
        int b;
        cin >> b; b--;
        B.insert(b);
    }

    sort(A.rbegin(), A.rend());
    int mx = A[0].first;
    string ans = "No";
    for (int i = 0; i < N; i++) {
        int id, a;
        tie(a, id) = A[i];
        if (a == mx) {
            if (B.count(id)) ans = "Yes";
        }
        else break;
    }
    cout << ans << endl;
}