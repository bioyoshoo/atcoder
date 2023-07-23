#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N; cin >> N;
    vector<string> S(N); rep(i, N) cin >> S[i];

    for (int i = N - 1; i >= 0; i--) {
        cout << S[i] << endl;
    }
}