#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int n_digits(ll n) {
    return to_string(n).size();
}

bool check753(ll n) {
    bool flag7 = false, flag5 = false, flag3 = false;
    while (n > 0) {
        if (n % 10 == 7) flag7 = true;
        else if (n % 10 == 5) flag5 = true;
        else if (n % 10 == 3) flag3 = true;
        n /= 10;
    }
    if (flag7 && flag5 && flag3) return true;
    else return false;
}

vector<ll> V;
vector<ll> c = {7, 5, 3};
void DFS(ll n) {
    if (n_digits(n) > 9) return;
    if (check753(n)) V.push_back(n);
    rep(i, 3) {
        ll next = 10 * n + c[i];
        DFS(next);
    }
}

int main() {
    ll N; cin >> N;
    DFS(0);
    sort(V.begin(), V.end());
    ll ans = lower_bound(V.begin(), V.end(), N + 1) - V.begin();
    cout << ans << endl;
}