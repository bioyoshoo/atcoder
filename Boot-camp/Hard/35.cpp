#include <bits/stdc++.h>
using namespace std;
using p = pair<int64_t, int64_t>;

int main() {
    int64_t N, H;
    cin >> N >> H;
    vector<p> K(N);
    for (int i = 0; i < N; i++) {
        int64_t a, b;
        cin >> a >> b;
        K.at(i) = make_pair(a, b);
    }

    sort(K.begin(), K.end());

    int64_t ans = 0;
    for (int i = 0; i <= N - 2; i++) {
        H -= K.at(i).second;
        ans++;
    }

    int64_t a, b;
    tie(a, b) = K.at(N - 1);

    while (H > b) {
        H -= a;
        ans++;
    }
    if (H > 0) ans++;

    cout << ans << endl;
}