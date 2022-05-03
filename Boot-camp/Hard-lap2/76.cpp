#include <bits/stdc++.h>
using namespace std;

int main() {
    long long S;
    cin >> S;
    int N = to_string(S).size();

    long long ans = 0;
    for (long long i = 0; i < (1LL << (N - 1)); i++) {
        long long n = S;
        long long a = 1;
        long long sum = 0;
        for (int j = 0; j < N - 1; j++) {
            a *= 10;
            if (i & (1LL << j)) {
                sum += n % a;
                n /= a;
                a = 1;
            }
        }
        sum += n;
        ans += sum;
    }
    cout << ans << endl;
}