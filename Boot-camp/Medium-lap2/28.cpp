#include <bits/stdc++.h>
using namespace std;

long double sum(int n) {
    if (n == 0) return 0;
    else return n + sum(n - 1);
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<long double> P(N + 1);
    P.at(0) = 0;
    for (int i = 1; i <= N; i++) {
        int p;
        cin >> p;
        P.at(i) = sum(p) / p;
    }
    
    for (int i = 1; i <= N; i++) P.at(i) += P.at(i - 1);
    long double ans = 0;
    for (int i = 1; i <= N; i++) {
        if (i + K - 1 > N) continue;
        ans = max(ans, P.at(i + K - 1) - P.at(i - 1));
    }

    cout << fixed << setprecision(12);
    cout << ans << endl;
}