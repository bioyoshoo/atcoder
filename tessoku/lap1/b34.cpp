#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int G(ll x) {
    if (x % 5 == 0 || x % 5 == 1) return 0;
    if (x % 5 == 2 || x % 5 == 3) return 1;
    if (x % 5 == 4) return 2;
    return -1;
}

int main() {
    int N, X, Y; cin >> N >> X >> Y;
    int sum = 0;
    rep(i, N) {
        ll a; cin >> a;
        sum ^= G(a);
    }
    
    if (sum == 0) cout << "Second" << endl;
    else cout << "First" << endl; 
}