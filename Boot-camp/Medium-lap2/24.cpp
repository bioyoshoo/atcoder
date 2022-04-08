#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, A, B;
    cin >> N >> A >> B;
    
    if (A > B) cout << 0 << endl;
    else if (N == 1 && A != B) cout << 0 << endl;
    else {
        int64_t m = A * (N - 1) + B;
        int64_t M = A + (N - 1) * B;
        cout << M - m + 1 << endl;
    }
}