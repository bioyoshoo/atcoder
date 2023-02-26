#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int A, B, C, X; cin >> A >> B >> C >> X;

    if (X <= A) cout << 1 << endl;
    else if (A + 1 <= X && X <= B) {
        cout << fixed << setprecision(10);
        cout << (double)C / (B - A) << endl;
    }
    else cout << 0 << endl;
}