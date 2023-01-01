#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool check(int h, int m) {
    int A, B, C, D;
    A = h / 10; B = h % 10; C = m / 10; D = m % 10;
    int s = 10 * A + C, t = 10 * B + D;
    if ((0 <= s && s <= 23) && (0 <= t && t <= 59)) return true;
    else return false;
}

pair<int, int> step(int h, int m) {
    if ((h == 23) && (m == 59)) return {0, 0};
    else if (m == 59) return {h + 1, 0};
    return {h, m + 1};
}

int main() {
    int h, m; cin >> h >> m;
    bool ok = false;
    
    while (!ok) {
        if (check(h, m)) {
            ok = true;
            break;
        }
        else {
            tie(h, m) = step(h, m);
        }
    }

    cout << h << " " << m << endl;
}
