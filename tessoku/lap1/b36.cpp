#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K; cin >> N >> K;
    string S; cin >> S;

    int cnt = 0;
    rep(i, N) if (S[i] == '1') cnt++;

    if (cnt % 2 == K % 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}