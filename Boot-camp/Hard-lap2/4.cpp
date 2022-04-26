#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t a, b, x;
    cin >> a >> b >> x;

    int64_t n_a, n_b;
    if (a == 0) n_a = 0;
    else n_a = (a - 1) / x;
    
    n_b = b / x;
    if (a == 0) n_b++;
    
    cout << n_b - n_a << endl;
}