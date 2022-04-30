#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int64_t> P(a), Q(b), R(c);
    for (int i = 0; i < a; i++) cin >> P.at(i);
    for (int i = 0; i < b; i++) cin >> Q.at(i);
    for (int i = 0; i < c; i++) cin >> R.at(i);
    sort(P.rbegin(), P.rend());
    sort(Q.rbegin(), Q.rend());

    for (int i = 0; i < x; i++) R.push_back(P[i]);
    for (int i = 0; i < y; i++) R.push_back(Q[i]);
    sort(R.rbegin(), R.rend());

    int64_t ans = 0;
    for (int i = 0; i < x + y; i++) ans += R[i];
    cout << ans << endl;
}