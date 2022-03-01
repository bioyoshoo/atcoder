#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int64_t ans = 1;
    for (int i = 0; i < N; i++) {
        int64_t t;
        cin >> t;
        ans = lcm(ans, t);
    }

    cout << ans << endl;
}