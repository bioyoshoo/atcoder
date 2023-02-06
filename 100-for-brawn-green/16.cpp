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

    vector<int> R = P;
    sort(R.begin(), R.end());
    
    int cnt = 0;
    int a = -1, b = -1;
    do {
        cnt++;
        if (P == R) a = cnt;
        if (Q == R) b = cnt;
    } while (next_permutation(R.begin(), R.end()));

    cout << abs(a - b) << endl;
}