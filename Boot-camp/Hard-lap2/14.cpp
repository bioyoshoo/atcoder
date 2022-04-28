#include <bits/stdc++.h>
using namespace std;

int keta(int64_t n) {
    string n_s = to_string(n);
    return n_s.size();
}

int main() {
    int64_t N;
    cin >> N;

    int ans = 20;
    for (int64_t a = 1; a * a <= N; a++) {
        if (N % a != 0) continue;
        int64_t b = N / a;
        int cand = max(keta(a), keta(b));
        ans = min(ans, cand);
    }

    cout << ans << endl;
}