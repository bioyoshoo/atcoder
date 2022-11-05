#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1e9;

int main() {
    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        vector<int> dp1(n + 1, INF), dp2(n + 1, INF);
        dp1[0] = 0; dp2[0] = 0;

        for (int i = 1; i*(i+1)*(i+2)/6 <= n; i++) {
            int a = i*(i+1)*(i+2)/6;
            for (int j = a; j <= n; j++) {
                dp1[j] = min(dp1[j], dp1[j - a] + 1);
                if (a % 2 == 1) dp2[j] = min(dp2[j], dp2[j - a] + 1);
            }
        }

        cout << dp1[n] << " " <<  dp2[n] << endl;
    }
}
