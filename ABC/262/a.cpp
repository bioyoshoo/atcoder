#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int Y; cin >> Y;

    if (Y % 4 == 0) cout << Y + 2 << endl;
    else if (Y % 4 == 1) cout << Y + 1 << endl;
    else if (Y % 4 == 2) cout << Y << endl;
    else cout << Y + 3 << endl;
}