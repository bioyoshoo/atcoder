#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;
    
    int64_t gcd_n, a_max = -1;
    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        a_max = max(a_max, a);
        if (i == 0) gcd_n = a;
        else gcd_n = gcd(gcd_n, a);
    }

    if (K > a_max) cout << "IMPOSSIBLE" << endl;
    else {
        if (K % gcd_n != 0) cout <<  "IMPOSSIBLE" << endl;
        else if (K % gcd_n == 0) cout << "POSSIBLE" << endl;
    }
}