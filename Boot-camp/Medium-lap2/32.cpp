#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;

    int ans_a = -1, ans_b = -1, ans_c = -1;
    for (int a = 0; a <= Y / 10000; a++) {
        for (int b = 0; b <= Y / 5000; b++) {
            int c = N - a - b;
            if (c < 0 || c > Y / 1000) continue;
            if (10000 * a + 5000 * b + 1000 * c == Y) {
                ans_a = a; ans_b = b; ans_c = c;
                goto OUT;
            }
        }
    }
OUT:
    cout << ans_a << " " <<  ans_b << " " << ans_c << endl;
}