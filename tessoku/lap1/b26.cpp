#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

vector<bool> erastotenes(int n) {
    vector<bool> res(n + 1, true);
    res[0] = res[1] = false;
    for (int x = 2; x <= n; x++) {
        if (!res[x]) continue;
        for (int y = 2 * x; y <= n; y += x) res[y] = false;
    }
    return res;
}

int main() {
    int N; cin >> N;

    vector<bool> res = erastotenes(N);
    for (int a = 2; a <= N; a++) {
        if (res[a]) cout << a << endl;
    }
}
