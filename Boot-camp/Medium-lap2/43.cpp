#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t X;
    cin >> X;

    int64_t ans = 0;
    int64_t i = 1, sum = 0;
    while (sum < X) {
        sum += i;
        ans++;
        i++;
    }

    cout << ans << endl;
}