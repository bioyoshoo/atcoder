#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t L, R;
    cin >> L >> R;

    if (gcd(L, R) == 1) cout << R - L << endl;
    else {
        int64_t ans = -1;
        int64_t l = L, r = R;
        while (l < R && gcd(l, R) != 1) l++;
        ans = max(ans, R - l);
        while (L < r && gcd(L, r) != 1) r--;
        ans = max(ans, r - L);

        l = L;
        r = R;
        char nex = 'L';
        while (l < R && L < r && gcd(l, r) != 1) {
            if (nex == 'L') {
                l++;
                nex = 'R';
            }
            else if (nex == 'R') {
                r--;
                nex = 'L';
            }
        }
        ans = max(ans, r - l);
        
        l = L;
        r = R;
        nex = 'R';
        while (l < R && L < r && gcd(l, r) != 1) {
            if (nex == 'L') {
                l++;
                nex = 'R';
            }
            else if (nex == 'R') {
                r--;
                nex = 'L';
            }
        }
        ans = max(ans, r - l);
        cout << ans << endl;
    }
}