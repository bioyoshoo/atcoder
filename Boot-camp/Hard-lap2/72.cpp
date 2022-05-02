#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    
    bool end = false;
    for (int64_t h = 1; h <= 3500; h++) {
        for (int64_t w = 1; w <= 3500; w++) {
            int64_t a = 4 * h * w - N * w - N * h;
            int64_t b = N * w * h;
            if (a == 0) continue;
            if (b % a != 0) continue;
            int64_t n = b / a;
            if (1 <= n && n <= 3500) {
                cout << h << " " << n << " " << w << endl;
                end = true;
                break;
            }
        }
        if (end) break;
    }
}