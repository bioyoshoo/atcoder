#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int64_t n = 0, sum = 0, diff;
    for (; n <= N; n++) {
        sum += n;
        if (sum >= N) {
            diff = sum - N;
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i != diff) cout << i << endl;
    }
}