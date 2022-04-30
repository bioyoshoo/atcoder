#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> A.at(i);
    for (int i = 1; i <= N; i++) A[i] += A[i - 1];

    map<int64_t, int64_t> mp;
    for (int i = 0; i <= N; i++) mp[A[i]]++;

    int64_t ans = 0;
    for (auto m: mp) ans += m.second * (m.second - 1) / 2;
    cout << ans << endl;
}