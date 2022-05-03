#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int64_t, int64_t, int64_t>;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A.at(i) >> B.at(i);
    
    vector<tiii> V(N);
    for (int i = 0; i < N; i++) {
        V.at(i) = {abs(A.at(i) + B.at(i)), A.at(i), B.at(i)};
    }
    sort(V.rbegin(), V.rend());

    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        int64_t a, b;
        tie(ignore, a, b) = V.at(i);
        if (i % 2 == 0) ans += a;
        else ans -= b;
    }
    cout << ans << endl;
}