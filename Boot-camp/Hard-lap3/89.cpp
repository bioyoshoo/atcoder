#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using mint = modint1000000007;

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];
    map<int, int> mp;
    
    mint ans = 1;
    rep(i, N) {
        if (A[i] == 0) ans *= max(0, 3 - mp[0]);
        else ans *= max(0, mp[A[i] - 1] - mp[A[i]]);
        mp[A[i]]++;
    }
    cout << ans.val() << endl;
}