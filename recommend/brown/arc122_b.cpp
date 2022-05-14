#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
    int N;
    cin >> N;
    vector<ld> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    sort(A.begin(), A.end());
    vector<ld> C(N);
    C[0] = A[0];
    for (int i = 1; i < N; i++) C[i] = C[i - 1] + A[i];
    ld ans = 1e15;
    for (int i = 0; i < N; i++) {
        ld x = A[i] / 2;
        
        int idx = lower_bound(A.begin(), A.end(), 2 * x) - A.begin();
        ld min_part = (N - idx) * 2 * x;
        if (idx != 0) min_part += C[idx - 1];

        ld exp = N * x + C[N - 1] - min_part;
        exp /= N;
        ans = min(ans, exp);
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;
}