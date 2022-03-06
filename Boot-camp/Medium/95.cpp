#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<pair<int64_t, int64_t>> V(N);
    for (int i = 0; i < N; i++) {
        int64_t a, b;
        cin >> a >> b;
        pair p = make_pair(a, b);
        V.at(i) = p;
    }

    sort(V.begin(), V.end());

    int64_t ans = 0, sum = 0;
    for (auto v: V) {
        sum += v.second;
        if (sum >= K) {
            ans = v.first;
            break;
        }
    }
    cout << ans << endl;
}