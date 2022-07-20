#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int div(int n) {
    int res = 0;
    while (n % 100 == 0) {
        n /= 100;
        res++;
    }
    return res;
}

int main() {
    int D, N; cin >> D >> N;

    int cnt = 0;
    for (int n = 1; n <= 1e7; n++) {
        if (div(n) == D) cnt++;
        if (cnt == N) {
            cout << n << endl;
            break;
        }
    }
}