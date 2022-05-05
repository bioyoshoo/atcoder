#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1000000007;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    int64_t ans = 1;
    map<int64_t, int64_t> mp;
    mp[0] = 3;
    for (int i = 0; i < N; i++) {
        ans = ans * mp[A[i]] % mod;
        mp[A[i]]--;
        mp[A[i] + 1]++;
    }
    cout << ans << endl;
}