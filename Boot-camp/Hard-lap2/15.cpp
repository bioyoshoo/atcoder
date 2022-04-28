#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    int64_t less_zero = 0, min_abs = 1e10, sum = 0;
    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        if (a <= 0) less_zero++;
        min_abs = min(min_abs, abs(a));
        sum += abs(a);
    }
    
    int64_t ans;
    if (less_zero % 2 == 0) ans = sum;
    else ans = sum - 2 * min_abs;
    cout << ans << endl;
}