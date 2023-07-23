#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int N, K;

bool dist(int x1, int y1, int x2, int y2) {
    if (abs(x1 - x2) <= K && abs(y1 - y2) <= K) return true;
    else return false;
}

int main() {
    cin >> N >> K;
    vector<int> A(N), B(N); rep(i, N) cin >> A[i] >> B[i];

    int ans = 0;
    for (int a = 1; a <= 100; a++) {
        for (int b = 1; b <= 100; b++) {
            int cnt = 0;
            for (int i = 0; i < N; i++) {
                if (!(a <= A[i] && A[i] <= a + K)) continue;
                if (!(b <= B[i] && B[i] <= b + K)) continue;

                cnt++;
            }

            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;
}
