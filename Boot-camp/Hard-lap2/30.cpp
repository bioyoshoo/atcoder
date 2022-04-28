#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> A(N);
    int64_t a_gcd, a_max = 0;
    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        a_max = max(a_max, a);
        if (i == 0) a_gcd = a;
        else a_gcd = gcd(a_gcd, a);
    }

    bool ans;
    if (K > a_max) ans = false;
    else {
        if (K % a_gcd == 0) ans = true;
        else ans = false;
    }

    if (ans) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}