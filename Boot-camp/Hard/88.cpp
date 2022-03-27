#include <bits/stdc++.h>
using namespace std;

int64_t bi_k(int64_t n) {
    if (n == 0) return 1;
    int64_t k = 0;
    while (n > 0) {
        k++;
        n >>= 1;
    }
    return k;
}
int main() {
    int64_t a, b;
    cin >> a >> b;

    int64_t k = bi_k(b);
    cout << k << endl;
}