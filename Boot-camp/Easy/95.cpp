#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int a, b, c; cin >> a >> b >> c;
    vector<int> V = {a, b, c};
    int sum = a + b + c;
    int max_n = max(a, max(b, c));
    rep(x, 200) {
        int final_sum = sum + 2 * x;
        
        if (final_sum % 3 != 0) continue;
        int bar = final_sum / 3;
        if (bar < max_n) continue;

        int cnt = 0, res = 0;
        rep(i, 3) {
            cnt += (bar - V[i]) / 2;
            if ((bar - V[i]) % 2 == 1) res++;
        }
        if (res % 2 == 0) cnt += res / 2;
        else continue;

        if (x == cnt) {
            cout << x << endl;
            break;
        }
    }
}