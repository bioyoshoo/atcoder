#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int K, T; cin >> K >> T;
    vector<int> A(T); rep(i, T) cin >> A[i];
    sort(A.rbegin(), A.rend());
    int a_max = A[0];
    int others = 0;
    for (int i = 1; i < T; i++) others += A[i];
    int ans = max(0, a_max - 1 - others);
    cout << ans << endl;
}