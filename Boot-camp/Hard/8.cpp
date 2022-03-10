#include <bits/stdc++.h>
using namespace std;

int64_t div_5(int64_t n) {
    int64_t ans = 0;
    while (n > 0) {
        ans += n / 5;
        n /= 5;
    }
    return ans;
}

int main() {
    int64_t N;
    cin >> N;

    if (N % 2 != 0) cout << 0 << endl;
    else {
        cout << div_5(N / 2) << endl;
    } 
}