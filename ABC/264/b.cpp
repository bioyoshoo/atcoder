#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int R, C; cin >> R >> C; R -= 8; C -= 8;

    if (max(abs(R), abs(C)) % 2 == 0) cout << "white" << endl;
    else cout << "black" << endl;
}