#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

vector<ll> P;
ll rec_p(ll level) {
    if (level == 0) return P[0] = 1;
    if (P[level] != -1) return P[level];
    return P[level] = 2 * rec_p(level - 1) + 1; 
}

vector<ll> L;
ll rec_l(ll level) {
    if (level == 0) return L[0] = 1;
    if (L[level] != -1) return L[level];
    return L[level] = 2 * rec_l(level - 1) + 3;
}

ll rec(int level, ll x) {
    if (level == 0 && x == 0) return 0;
    if (level == 0 && x == 1) return 1;
    if (x <= 1) return 0;
    if (2 <= x && x <= L[level - 1] + 1) return rec(level - 1, x - 1);
    if (x == L[level - 1] + 2) return P[level - 1] + 1;
    if (L[level - 1] + 2 < x && x <= 2 * L[level - 1] + 2) return rec(level - 1, x - L[level - 1] - 2) + P[level - 1] + 1;
    else return 2 * P[level - 1] + 1;
}

int main() {
    ll N; ll X;
    cin >> N >> X;
    
    P.assign(N + 1, -1);
    rec_p(N);
    L.assign(N + 1, -1);
    rec_l(N);

    cout << rec(N, X) << endl;
}