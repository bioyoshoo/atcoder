#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t L, R;
    cin >> L >> R;

    if (R - L >= 2019) cout << 0 << endl;
    else {
        for (int n = L; n <= R; n++) {
            if (n % 2019 == 0) {
                cout << 0 << endl;
                break;
            }
        }
        cout << (L % 2019) * ((L % 2019) + 1) << endl;
    }
}