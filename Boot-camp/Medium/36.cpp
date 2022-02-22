#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    int ans;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        
        if (i == 0) ans = abs(X - x);
        else ans = gcd(ans, abs(X - x));
    }
    cout << ans << endl;
}