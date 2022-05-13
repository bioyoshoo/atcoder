#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    long double N;
    cin >> N;
    vector<long double> A(N);
    long double all_sum = 0;
    for (int i = 0; i < N; i++) {
        long double a; cin >> a;
        all_sum += a;
        A.at(i) = a;
    }
    sort(A.begin(), A.end());

    long double ans = 1e15, sum = 0;
    for (int i = 0; i < N; i++) {
        long double x = A.at(i) / 2;
        long double loss = N * x + all_sum - sum - (N - i) * 2 * x;
        loss /= N;
        ans = min(ans, loss);
        sum += A.at(i);
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;
}