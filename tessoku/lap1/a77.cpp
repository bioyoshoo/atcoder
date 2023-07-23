#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, L; cin >> N >> L;
    int K; cin >> K;
    vector<int> A(N); rep(i, N) cin >> A[i]; 

    int left = 0, right = L + 1;
    while (right - left > 1) {
        int x = (left + right) / 2;

        int prev = 0, cnt = 0;
        bool ok = false;
        rep(i, N) {
            int length = A[i] - prev;
            if (length >= x) {
                prev = A[i];
                cnt++;
            }

            if (cnt == K && L - prev >= x) {
                ok = true;
                break;
            }
        }

        if (ok) left = x;
        else right = x;
    }

    cout << left << endl;
}
