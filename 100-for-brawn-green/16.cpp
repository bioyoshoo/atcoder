#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<int> P(N), Q(N);
    rep(i, N) cin >> P[i];
    rep(i, N) cin >> Q[i];

    vector<int> V;
    rep(i, N) V.push_back(i + 1);

    int a = -1, b = -1;
    int cnt = 0;
    do {
        if (V == P) a = cnt;
        if (V == Q) b = cnt;
        cnt++;
    } while (next_permutation(V.begin(), V.end()));

    cout << abs(a - b) << endl;
}