#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K; cin >> N >> K;

    if ((K % 2 == 0) && (2 * N - 2 <= K)) cout << "Yes" << endl;
    else cout << "No" << endl;
}