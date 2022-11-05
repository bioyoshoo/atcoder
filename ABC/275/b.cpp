#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint998244353;
const ll mod = 998244353;

int main() {
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    A %= mod;
    B %= mod;
    C %= mod;
    D %= mod;
    E %= mod;
    F %= mod;
    

    mint X = A, Y = D;
    X *= B; X *= C;
    Y *= E; Y *= F;

    mint ans = X - Y;
    cout << ans.val() << endl;
}