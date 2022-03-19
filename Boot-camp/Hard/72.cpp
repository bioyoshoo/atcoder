#include <bits/stdc++.h>
using namespace std;

bool is_int(long double n) {
    if (floor(n) == n) return true;
    else return false;
}

int main() {
    int64_t N;
    cin >> N;

    bool flag = false;
    for (int h = 1; h <= 3500; h++) {
        for (int n = 1; n <= 3500; n++) {
            int64_t devo = 4 * h * n - N * h - N * n;
            if (devo <= 0) continue;
            long double w = (long double)(N * h * n) / devo;
            if (is_int(w)) {
                cout << h << " " <<  n << " " << (int64_t)w << endl;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
}