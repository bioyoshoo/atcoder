#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;

    long long ans = 0;
    for (long long a = 1; a * a * a <= N; a++) {
        for (long long b = a; b * b <= N / a; b++) {
            if (b <= N / (a * b)) ans += N / (a * b) - b + 1;
        }
    }
    cout << ans << endl;
}