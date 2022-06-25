#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    bool ans = true;
    rep(i, N) {
        ll a; cin >> a;
        if (a % 2 != 0) ans = false;
    }
    if (ans) cout << "second" << endl;
    else cout << "first" << endl;
}