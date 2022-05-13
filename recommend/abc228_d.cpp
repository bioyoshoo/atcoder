#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = (1LL << 20);

vector<ll> to;
ll root(ll n) {
    if (to[n] == -1) return n;
    else return to[n] = root(to[n]);
}

int main() {
    int Q; cin >> Q;
    vector<ll> A(N, -1);

    to.assign(N, -1);

    for (int i = 0; i < Q; i++) {
        ll t, x; cin >> t >> x;
        if (t == 1) {
            ll next = root(x % N);
            A[next] = x;
            to[next] = (next + 1) % N;
        }
        else if (t == 2) {
            cout << A[x % N] << endl;
        }
    }
}