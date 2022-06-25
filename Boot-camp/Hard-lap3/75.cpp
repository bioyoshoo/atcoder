#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K; cin >> N >> K;
    string S; cin >> S;

    ll ans = 0;
    int right = 0;
    int block = 0;
    for (int left = 0; left < N;) {
        while (right < N && S[left] == S[right]) right++;
        ans += right - left - 1;
        block++;
        left = right;
    }
    ans += min(2 * K, block - 1);
    cout << ans << endl;
}