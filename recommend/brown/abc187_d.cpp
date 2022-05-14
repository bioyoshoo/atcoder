#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long diff = 0;
    vector<long long> V;
    for (int i = 0; i < N; i++) {
        long long a, b; cin >> a >> b;
        V.push_back(2 * a + b);
        diff -= a;
    }
    sort(V.rbegin(), V.rend());

    int ans = 0;
    for (auto v: V) {
        diff += v;
        ans++;
        if (diff > 0) break;
    }

    cout << ans << endl;
}