#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    string ans = "";

    int cnt = 1;
    while (cnt >= 0) {
        int res = N / (int)pow(16, cnt);
        if (res < 10) ans += (char)('0' + res);
        else ans += (char)('A' + (res - 10));

        N -= (int)pow(16, cnt) * res;
        cnt--;
    }

    cout << ans << endl;
}