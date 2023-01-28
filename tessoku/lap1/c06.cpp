#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    cout << N << endl;
    for (int i = 1; i < N; i++) {
        cout << i << " " << i + 1 << endl;
    }
    cout << 1 << " " << N << endl;
}
