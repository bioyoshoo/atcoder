#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int X, Y, Z; cin >> X >> Y >> Z;

    if (X < 0) {
        X = -X; Y = -Y; Z = -Z;
    }

    if (0 < Y && Y < X) {
        if (Y < Z) cout << -1 << endl;
    else cout << abs(Z) + abs(X - Z) << endl;
    }
    else cout << X << endl;
}